#include"stdafx.h"
#include "PrimitiveHaveAnInterViewTask.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
PrimitiveHaveAnInterViewTask::PrimitiveHaveAnInterViewTask()
	: mCost(0)
{
}


//==================================================
// �f�X�g���N�^
//==================================================
PrimitiveHaveAnInterViewTask::~PrimitiveHaveAnInterViewTask()
{
}

//==================================================
// �J�n
//==================================================
void PrimitiveHaveAnInterViewTask::start()
{
	printf("InterviewStart\n");
}

//==================================================
// �X�V
//==================================================
void PrimitiveHaveAnInterViewTask::update()
{
	printf("-----------------\nInterView!!!%d\n-----------------\n", mCost);
}

//==================================================
// �I��
//==================================================
void PrimitiveHaveAnInterViewTask::end()
{
	printf("InterviewEndt\n");
}

//==================================================
// �R�X�g�擾
//==================================================
float PrimitiveHaveAnInterViewTask::getCost()
{
	return mCost;
}

//==================================================
// �v���~�e�B�u�^�X�N��
//==================================================
bool PrimitiveHaveAnInterViewTask::isPrimitive()
{
	return true;
}

//==================================================
// �O�����𖞂����Ă��邩
//==================================================
bool PrimitiveHaveAnInterViewTask::evaluatePreCondition(HtnState* state)
{
	if (!state->getB())
	{
		return true;
	}
	return false;
}

//==================================================
// �X�e�[�^�X�ύX�𔽉f����
//==================================================
void PrimitiveHaveAnInterViewTask::changeStatus(HtnState* state)
{
	state->setB(true);
}

//==================================================
// �^�X�N���I��������
//==================================================
bool PrimitiveHaveAnInterViewTask::isFinish()
{
	return true;
}
