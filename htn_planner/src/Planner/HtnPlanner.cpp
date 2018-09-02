#include"stdafx.h"
#include "HtnPlanner.h"
#include "../Htnobject/PrimitiveTask/PrimitiveBuyMaterialsTask.h"
#include "../Htnobject/PrimitiveTask/PrimitiveBuyRetortTask.h"
#include "../Htnobject/PrimitiveTask/PrimitiveCutMaterialsTask.h"
#include "../Htnobject/PrimitiveTask/PrimitivePutRouxTask.h"
#include "../Htnobject/PrimitiveTask/PrimitiveSimmerTask.h"
#include "../Htnobject/PrimitiveTask/PrimitiveStirFryTask.h"
#include "../Htnobject/TaskBase.h"
#include "../Htnobject/State.h"
#include "../Htnobject/Goal.h"

using namespace htn;


//==================================================
// コンストラクタ
//==================================================
HtnPlanner::HtnPlanner()
	: mDomainCount(0)
	, mTaskCount(0)
	, mCurrentTaskNo(0)
	, mIsCallTaskStart(true)
	, mPlanstateCount(0)
{
}

//==================================================
// デストラクタ
//==================================================
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

//==================================================
// ドメインにタスクを登録する
//==================================================
void HtnPlanner::registerDomain(TaskBase* task)
{
	mDomain[mDomainCount] = task;
	mDomainCount++;
}

//==================================================
// 実行するタスクを登録する
//==================================================
void HtnPlanner::registerTask(TaskBase* task)
{
	mTasks[mTaskCount] = task;
	mTaskCount++;
}

//==================================================
// 探索に使用するステートを登録する
//==================================================
void htn::HtnPlanner::registerState(AstarStateNode * node)
{
	mPlanStates[mPlanstateCount] = node;
	mPlanstateCount++;
}

//==================================================
// 初期設定
//==================================================
void HtnPlanner::setup()
{
	// TODO :TaskBaseを継承したクラスを自動で登録する

	PrimitiveBuyMaterialsTask* task1 = new PrimitiveBuyMaterialsTask();
	registerDomain(task1);

	PrimitiveBuyRetortTask* task2 = new PrimitiveBuyRetortTask();
	registerDomain(task2);
	
	PrimitiveCutMaterialsTask* task3 = new PrimitiveCutMaterialsTask();
	registerDomain(task3);

	PrimitivePutRouxTask* task4 = new PrimitivePutRouxTask();
	registerDomain(task4);

	PrimitiveSimmerTask* task5 = new PrimitiveSimmerTask();
	registerDomain(task5);

	PrimitiveStirFryTask* task6 = new PrimitiveStirFryTask();
	registerDomain(task6);
}

//==================================================
// プランニングを行う
//==================================================
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

				// todo newしないでいい方法を考える
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

		if (minCostNode != nullptr)
		{
			if (goal->evaluate(minCostNode) == 0)
			{
				break;
			}
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

//==================================================
// 検索に使用する状態がすべてCloseしているか
//==================================================
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

//==================================================
// 同じ条件のノードがあれば返す
//==================================================
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

//==================================================
// コストが最小のノードを返す
//==================================================
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

//==================================================
// タスクの実行を行う（falseを返せば終了）
//==================================================
bool HtnPlanner::updateTask()
{
	if (mTaskCount == 0)
	{
		printf("プランが作成されませんでした");
		return false;
	}

	if (mIsCallTaskStart)
	{
		mTasks[mTaskCount - 1 - mCurrentTaskNo]->start();
	}

	// 階層型タスク
	if (!mTasks[mTaskCount - 1 - mCurrentTaskNo]->isPrimitive())
	{
		// todo HTN
	}

	mTasks[mTaskCount - 1 - mCurrentTaskNo]->update();

	if (mTasks[mTaskCount - 1 - mCurrentTaskNo]->isFinish())
	{
		mTasks[mTaskCount - 1 - mCurrentTaskNo]->end();
		if (!nextTask())
		{
			return false;
		}

		mIsCallTaskStart = true;
	}
	return true;
}

//==================================================
// 次のタスクに切り替える
//==================================================
bool HtnPlanner::nextTask()
{
	mCurrentTaskNo++;
	return !(mCurrentTaskNo == mTaskCount);
}