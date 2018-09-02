#ifndef _HTN_PLANNER_PLANNER_H_
#define _HTN_PLANNER_PLANNER_H_

#include "../../stdafx.h"
#include "../Htnobject/State.h"
#include "../Htnobject/TaskBase.h"
#include "../Htnobject/Goal.h"
#include "AstarStateNode.h"

namespace htn
{
	class HtnPlanner
	{
	public:
		// �R���X�g���N�^
		HtnPlanner();

		// �f�X�g���N�^
		virtual ~HtnPlanner();

		// �h���C���Ƀ^�X�N��o�^����
		void registerDomain(TaskBase* task);

		// ���s����^�X�N��o�^����
		void registerTask(TaskBase* task);

		// �T���Ɏg�p����X�e�[�g��o�^����
		void registerState(AstarStateNode* node);

		//�^�X�N���N���A����
		inline void clearTask()
		{
			mTaskCount = 0;
		}

		// �����ݒ�
		void setup();

		// �v�����j���O���s��
		void plan(HtnState* state, Goal* goal);

		// �����Ɏg�p�����Ԃ����ׂ�Close���Ă��邩
		bool isAllStateClose();

		// ���������̃m�[�h������ΕԂ�
		AstarStateNode* haveSameNode(AstarStateNode* node);

		// �R�X�g���ŏ��̃m�[�h��Ԃ�
		AstarStateNode* pickMinCostNode();

		// �^�X�N�̎��s���s���ifalse��Ԃ��ΏI���j
		bool updateTask();

		// ���̃^�X�N�ɐ؂�ւ���
		bool nextTask();

	private:
		TaskBase* mDomain[1024];				// �h���C��
		unsigned int mDomainCount;				// �h���C����

		TaskBase* mTasks[1024];					// �^�X�N
		unsigned int mTaskCount;				// �^�X�N��

		AstarStateNode* mPlanStates[1024];		// �v����
		unsigned int mPlanstateCount;			// �v������

		int mCurrentTaskNo;						// ���݂̃^�X�N�ԍ�
		bool mIsCallTaskStart;					// �^�X�N�̃X�^�[�g���ĂԂ�
	};
}

#endif