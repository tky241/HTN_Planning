#include"stdafx.h"
#include "PrimitiveBuyRetortTask.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
PrimitiveBuyRetortTask::PrimitiveBuyRetortTask()
{
}

//==================================================
// �f�X�g���N�^
//==================================================
PrimitiveBuyRetortTask::~PrimitiveBuyRetortTask()
{
}

//==================================================
// �J�n
//==================================================
void PrimitiveBuyRetortTask::start()
{
	printf("���g���g�J���[�𔃂��ɍs���܂�\n");
}

//==================================================
// �X�V
//==================================================
void PrimitiveBuyRetortTask::update()
{
	printf("���g���g�J���[�𔃂��B1000�~����܂����B\n");
}

//==================================================
// �I��
//==================================================
void PrimitiveBuyRetortTask::end()
{
	printf("�Ƃɖ߂�܂��B\n");
}

//==================================================
// �R�X�g�擾
//==================================================
float PrimitiveBuyRetortTask::getCost()
{
	return 1;
}

//==================================================
// �v���~�e�B�u�^�X�N���ifalse�͊K�w�^�^�X�N�j
//==================================================
bool PrimitiveBuyRetortTask::isPrimitive()
{
	return true;
}

//==================================================
// �O�����𖞂����Ă��邩
//==================================================
bool PrimitiveBuyRetortTask::evaluatePreCondition(HtnState* state)
{
	if (state->getMoney() > 1000)
	{
		return true;
	}
	return false;
}

//==================================================
// �X�e�[�^�X��ύX����
//==================================================
void PrimitiveBuyRetortTask::changeStatus(HtnState* state)
{
	state->setMoney(state->getMoney() - 1000);
	state->setCurry(true);
}

//==================================================
// �^�X�N���I��������
//==================================================
bool PrimitiveBuyRetortTask::isFinish()
{
	return true;
}
