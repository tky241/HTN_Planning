#ifndef _HTN_PRIMITIVETASK_PrimitiveBuyRetortTask_H_
#define _HTN_PRIMITIVETASK_PrimitiveBuyRetortTask_H_

#include "../../../stdafx.h"
#include "../TaskBase.h"
#include "../State.h"

namespace htn
{
	class PrimitiveBuyRetortTask : public TaskBase
	{
	public:
		// �R���X�g���N�^
		PrimitiveBuyRetortTask();

		// �f�X�g���N�^
		virtual ~PrimitiveBuyRetortTask();

		// �J�n����
		virtual void start();

		// �X�V
		virtual void update();

		// �I��
		virtual void end();

		// �R�X�g�擾
		virtual float getCost();

		// �v���~�e�B�u�^�X�N���ǂ���
		virtual bool isPrimitive();

		// �O�����𖞂����Ă��邩
		virtual bool evaluatePreCondition(HtnState* state);

		// �X�e�[�^�X�̕ύX
		virtual void changeStatus(HtnState* state);

		// �^�X�N���I�����Ă��邩
		virtual bool isFinish();

	};
}

#endif