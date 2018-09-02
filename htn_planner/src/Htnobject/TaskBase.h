#ifndef _HTN_PLANNER_TASKBASE_H_
#define _HTN_PLANNER_TASKBASE_H_

#include "../../stdafx.h"
#include "State.h"

namespace htn
{
	class TaskBase
	{
	public:
		// �R���X�g���N�^
		TaskBase();

		// �f�X�g���N�^
		virtual ~TaskBase();

		// �J�n
		virtual void start() = 0;

		// �X�V
		virtual void update() = 0;

		// �I��
		virtual void end() = 0;

		// �R�X�g�擾
		virtual float getCost() = 0;

		// �v���~�e�B�u�^�X�N���ǂ���
		virtual bool isPrimitive() = 0;

		// �O�����𖞂����Ă��邩
		virtual bool evaluatePreCondition(HtnState* state) = 0;

		// �X�e�[�^�X�̕ύX
		virtual void changeStatus(HtnState* state) = 0;

		// �^�X�N���I��������
		virtual bool isFinish() = 0;

	private:

	};
}

#endif