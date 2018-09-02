#include"stdafx.h"
#include "HtnPlanner.h"
#include "../Htnobject/PrimitiveTask/PrimitiveGoTask.h"
#include "../Htnobject/PrimitiveTask/PrimitiveHaveAnInterviewTask.h"
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

	PrimitiveGoTask* task1 = new PrimitiveGoTask();
	registerDomain(task1);

	// �R�X�g�̈Ⴄ2��ނ̃^�X�N��o�^���āA�R�X�g�̏������ق����g�p����Ă��邱�Ƃ��m���߂�
	PrimitiveHaveAnInterViewTask* task2 = new PrimitiveHaveAnInterViewTask();
	task2->setCost(1);
	registerDomain(task2);
	PrimitiveHaveAnInterViewTask* task3 = new PrimitiveHaveAnInterViewTask();
	task3->setCost(100000);
	registerDomain(task3);
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
		mTasks[mCurrentTaskNo]->start();
	}

	// �K�w�^�^�X�N
	if (!mTasks[mCurrentTaskNo]->isPrimitive())
	{
		// todo HTN
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

//==================================================
// ���̃^�X�N�ɐ؂�ւ���
//==================================================
bool HtnPlanner::nextTask()
{
	mCurrentTaskNo++;
	return !(mCurrentTaskNo == mTaskCount);
}