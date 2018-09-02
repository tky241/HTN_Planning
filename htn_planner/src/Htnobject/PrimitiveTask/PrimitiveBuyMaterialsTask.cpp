#include"stdafx.h"
#include "PrimitiveBuyMaterialsTask.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
PrimitiveBuyMaterialsTask::PrimitiveBuyMaterialsTask()
{
}

//==================================================
// �f�X�g���N�^
//==================================================
PrimitiveBuyMaterialsTask::~PrimitiveBuyMaterialsTask()
{
}

//==================================================
// �J�n
//==================================================
void PrimitiveBuyMaterialsTask::start()
{
	printf("���܂���ޗ��𔃂��ɍs���܂�\n");
}

//==================================================
// �X�V
//==================================================
void PrimitiveBuyMaterialsTask::update()
{
	printf("�ޗ��𔃂��܂���\n");
}

//==================================================
// �I��
//==================================================
void PrimitiveBuyMaterialsTask::end()
{
	printf("�Ƃɖ߂��Ă��܂���\n");
}

//==================================================
// �R�X�g�擾
//==================================================
float PrimitiveBuyMaterialsTask::getCost()
{
	return 1;
}

//==================================================
// �v���~�e�B�u�^�X�N���ifalse�͊K�w�^�^�X�N�j
//==================================================
bool PrimitiveBuyMaterialsTask::isPrimitive()
{
	return true;
}

//==================================================
// �O�����𖞂����Ă��邩
//==================================================
bool PrimitiveBuyMaterialsTask::evaluatePreCondition(HtnState* state)
{
	if (state->haveBeef() && state->haveCarrot() && state->haveOnion() && state->havePtato())
	{
		return false;
	}
	return true;
}

//==================================================
// �X�e�[�^�X��ύX����
//==================================================
void PrimitiveBuyMaterialsTask::changeStatus(HtnState* state)
{
	state->setCarrot(true);
	state->setHaveBeef(true);
	state->setHaveOnion(true);
	state->setHavePtato(true);
}

//==================================================
// �^�X�N���I��������
//==================================================
bool PrimitiveBuyMaterialsTask::isFinish()
{
	return true;
}
