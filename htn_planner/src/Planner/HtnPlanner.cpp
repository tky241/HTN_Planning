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
// �R���X�g���N�^
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
// �f�X�g���N�^
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
// �h���C���Ƀ^�X�N��o�^����
//==================================================
void HtnPlanner::registerDomain(TaskBase* task)
{
	mDomain[mDomainCount] = task;
	mDomainCount++;
}

//==================================================
// ���s����^�X�N��o�^����
//==================================================
void HtnPlanner::registerTask(TaskBase* task)
{
	mTasks[mTaskCount] = task;
	mTaskCount++;
}

//==================================================
// �T���Ɏg�p����X�e�[�g��o�^����
//==================================================
void htn::HtnPlanner::registerState(AstarStateNode * node)
{
	mPlanStates[mPlanstateCount] = node;
	mPlanstateCount++;
}

//==================================================
// �����ݒ�
//==================================================
void HtnPlanner::setup()
{
	// TODO :TaskBase���p�������N���X�������œo�^����

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
// �v�����j���O���s��
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

				// todo new���Ȃ��ł������@���l����
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
// �����Ɏg�p�����Ԃ����ׂ�Close���Ă��邩
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
// ���������̃m�[�h������ΕԂ�
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
// �R�X�g���ŏ��̃m�[�h��Ԃ�
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
// �^�X�N�̎��s���s���ifalse��Ԃ��ΏI���j
//==================================================
bool HtnPlanner::updateTask()
{
	if (mTaskCount == 0)
	{
		printf("�v�������쐬����܂���ł���");
		return false;
	}

	if (mIsCallTaskStart)
	{
		mTasks[mTaskCount - 1 - mCurrentTaskNo]->start();
	}

	// �K�w�^�^�X�N
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
// ���̃^�X�N�ɐ؂�ւ���
//==================================================
bool HtnPlanner::nextTask()
{
	mCurrentTaskNo++;
	return !(mCurrentTaskNo == mTaskCount);
}