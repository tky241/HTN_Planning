#include"stdafx.h"
#include "PrimitivePutRouxTask.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
PrimitivePutRouxTask::PrimitivePutRouxTask()
{
}

//==================================================
// �f�X�g���N�^
//==================================================
PrimitivePutRouxTask::~PrimitivePutRouxTask()
{
}

//==================================================
// �J�n
//==================================================
void PrimitivePutRouxTask::start()
{
	printf("���낻�냋�[�����悤\n");
}

//==================================================
// �X�V
//==================================================
void PrimitivePutRouxTask::update()
{
	printf("���[������\n");
}

//==================================================
// �I��
//==================================================
void PrimitivePutRouxTask::end()
{
	printf("���[�����܂����J���[�̊����ł��B\n");
}

//==================================================
// �R�X�g�擾
//==================================================
float PrimitivePutRouxTask::getCost()
{
	return 1;
}

//==================================================
// �v���~�e�B�u�^�X�N���ifalse�͊K�w�^�^�X�N�j
//==================================================
bool PrimitivePutRouxTask::isPrimitive()
{
	return true;
}

//==================================================
// �O�����𖞂����Ă��邩
//==================================================
bool PrimitivePutRouxTask::evaluatePreCondition(HtnState* state)
{
	if (state->isBoil() && !state->isPutRoux())
	{
		return true;
	}
	return false;
}

//==================================================
// �X�e�[�^�X��ύX����
//==================================================
void PrimitivePutRouxTask::changeStatus(HtnState* state)
{
	state->setPutRoux(true);
}

//==================================================
// �^�X�N���I��������
//==================================================
bool PrimitivePutRouxTask::isFinish()
{
	return true;
}
