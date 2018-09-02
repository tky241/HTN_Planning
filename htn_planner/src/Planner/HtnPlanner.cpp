#include"stdafx.h"
#include "HtnPlanner.h"
#include "../Htnobject/PrimitiveTask/PrimitiveGoTask.h"
#include "../Htnobject/PrimitiveTask/PrimitiveHaveAnInterviewTask.h"
#include "../Htnobject/TaskBase.h"
#include "../Htnobject/State.h"
#include "../Htnobject/Goal.h"

using namespace htn;

HtnPlanner::HtnPlanner()
	: mDomainCount(0)
	, mTaskCount(0)
	, mCurrentTaskNo(0)
	, mIsCallTaskStart(true)
{
}

HtnPlanner::~HtnPlanner()
{
	for (unsigned int i = 0; i < mDomainCount; i++)
	{
		delete mDomain[i];
	}
}

void HtnPlanner::registerDomain(TaskBase* task)
{
	mDomain[mDomainCount] = task;
	mDomainCount++;
}

void HtnPlanner::registerTask(TaskBase* task)
{
	mTasks[mTaskCount] = task;
	mTaskCount++;
}

void HtnPlanner::setup()
{
	// TODO :TaskBaseを継承したクラスを自動で登録する

	PrimitiveGoTask* tas1 = new PrimitiveGoTask();
	tas1->setCost(1);
	registerDomain(tas1);
	PrimitiveHaveAnInterViewTask* tas2 = new PrimitiveHaveAnInterViewTask();
	tas2->setCost(2);
	registerDomain(tas2);
	PrimitiveHaveAnInterViewTask* tas3 = new PrimitiveHaveAnInterViewTask();
	tas3->setCost(3);
	registerDomain(tas3);
}

void HtnPlanner::plan(HtnState* state, Goal* goal)
{
	//// TODO : 現在はプランニングではない
	//for (unsigned int i = 0; i < mDomainCount; i++)
	//{
	//	registerTask(mDomain[i]);
	//}

	//return;

	HtnState planState;
	state->copyTo(planState);

	while (goal->evaluate(state) != 0)
	{
		bool isChange = false;

		for (unsigned int i = 0; i < mDomainCount; i++)
		{
			if (mDomain[i]->evaluatePreCondition(state))
			{
				registerTask(mDomain[i]);
				mDomain[i]->changeStatus(state);
				isChange = true;
			}
		}

		if (!isChange)
		{
			printf("プランニングに失敗しました。");
			break;
		}
	}
}

bool HtnPlanner::updateTask()
{
	if (mIsCallTaskStart)
	{
		mTasks[mCurrentTaskNo]->start();
	}

	mTasks[mCurrentTaskNo]->update();

	if (mTasks[mCurrentTaskNo]->isFinish())
	{
		mTasks[mCurrentTaskNo]->end();
		if (!nextTask())
		{
			return false;
		}

		mIsCallTaskStart = true;
	}
	return true;
}

bool HtnPlanner::nextTask()
{
	mCurrentTaskNo++;
	return !(mCurrentTaskNo == mTaskCount);
}