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
	, mPlanstateCount(0)
{
}

HtnPlanner::~HtnPlanner()
{
	for (unsigned int i = 0; i < mDomainCount; i++)
	{
		delete mDomain[i];
	}

	for (unsigned int i = 0; i < mPlanstateCount; i++)
	{
		delete mPlanStates[i];
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

void htn::HtnPlanner::registerState(AstarStateNode * node)
{
	mPlanStates[mPlanstateCount] = node;
	mPlanstateCount++;
}

void HtnPlanner::setup()
{
	// TODO :TaskBase‚ðŒp³‚µ‚½ƒNƒ‰ƒX‚ðŽ©“®‚Å“o˜^‚·‚é

	PrimitiveGoTask* tas1 = new PrimitiveGoTask();
	tas1->setCost(1);
	registerDomain(tas1);
	PrimitiveHaveAnInterViewTask* tas2 = new PrimitiveHaveAnInterViewTask();
	tas2->setCost(1);
	registerDomain(tas2);
	PrimitiveHaveAnInterViewTask* tas3 = new PrimitiveHaveAnInterViewTask();
	tas3->setCost(3);
	registerDomain(tas3);
}

void HtnPlanner::plan(HtnState* state, Goal* goal)
{
	HtnState planState;
	state->copyTo(planState);

	AstarStateNode* startnode = new AstarStateNode();
	state->copyTo(*startnode);
	registerState(startnode);
	AstarStateNode* minCostNode = pickMinCostNode();

	while (minCostNode != nullptr)
	{
		minCostNode->setClose(true);
		for (unsigned int i = 0; i < mDomainCount; i++)
		{
			if (mDomain[i]->evaluatePreCondition(minCostNode))
			{
				AstarStateNode* node = new AstarStateNode();;
				minCostNode->copyTo(*node);
				mDomain[i]->changeStatus(node);

				AstarStateNode* samenode = haveSameNode(node);
				if (samenode == nullptr)
				{
					node->setBeforStateNode(minCostNode);
					node->setBeforTask(mDomain[i]);
					node->setHeuristic(goal->evaluate(node));
					node->setCost(minCostNode->getCost() + mDomain[i]->getCost());
					registerState(node);

					
				}
				else
				{
					int cost = minCostNode->getCost() + mDomain[i]->getCost();
					if (samenode->getCost() > cost)
					{
						samenode->setBeforStateNode(minCostNode);
						samenode->setBeforTask(mDomain[i]);
					}

					delete node;
				}
			}
		}



		minCostNode = pickMinCostNode();
		if (goal->evaluate(minCostNode) == 0)
		{
			break;
		}
	}


	while (minCostNode != nullptr)
	{
		if (minCostNode->getBeforTask() == nullptr)
		{
			break;
		}

		registerTask(minCostNode->getBeforTask());
		minCostNode = minCostNode->getBeforStateNode();
	}
}

bool htn::HtnPlanner::isAllStateClose()
{
	for (unsigned int i = 0; i < mPlanstateCount; i++)
	{
		if (!mPlanStates[i]->isClose())
		{
			return false;
		}
	}
	return true;
}

AstarStateNode* htn::HtnPlanner::haveSameNode(AstarStateNode* node)
{
	for (unsigned int i = 0; i < mPlanstateCount; i++)
	{
		if (mPlanStates[i]->isSame(node))
		{
			return mPlanStates[i];
		}
	}
	return nullptr;
}

AstarStateNode * htn::HtnPlanner::pickMinCostNode()
{
	AstarStateNode* minCostNode = nullptr;
	for (unsigned int i = 0; i < mPlanstateCount; i++)
	{
		if (!mPlanStates[i]->isClose())
		{
			if (minCostNode == nullptr)
			{
				minCostNode = mPlanStates[i];
			}
			else
			{
				if (mPlanStates[i]->getTotalCost() < minCostNode->getTotalCost())
				{
					minCostNode = mPlanStates[i];
				}
			}
		}
	}
	return minCostNode;
}

bool HtnPlanner::updateTask()
{
	if (mTaskCount == 0)
	{
		printf("ƒvƒ‰ƒ“‚ªì¬‚³‚ê‚Ü‚¹‚ñ‚Å‚µ‚½");
		return false;
	}

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