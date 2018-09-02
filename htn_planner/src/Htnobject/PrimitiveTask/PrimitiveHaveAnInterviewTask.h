#ifndef _HTN_PRIMITIVETASK_INTERVIEWTASK_H_
#define _HTN_PRIMITIVETASK_INTERVIEWTASK_H_

#include "../../../stdafx.h"
#include "../TaskBase.h"
#include "../State.h"

namespace htn
{
	class PrimitiveHaveAnInterViewTask : public TaskBase
	{
	public:
		// �R���X�g���N�^
		PrimitiveHaveAnInterViewTask();

		// �f�X�g���N�^
		virtual ~PrimitiveHaveAnInterViewTask();

		// �J�n
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

		// �^�X�N���I��������
		virtual bool isFinish();

		// �R�X�g�̐ݒ�i�O������R�X�g�𑀍삵�ē�����m�F����p�j
		inline void setCost(int cost)
		{
			mCost = cost;
		}
	private:
		int mCost;
	};
}

#endif