#include"stdafx.h"
#include "PrimitiveCutMaterialsTask.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
PrimitiveCutMaterialsTask::PrimitiveCutMaterialsTask()
{
}

//==================================================
// �f�X�g���N�^
//==================================================
PrimitiveCutMaterialsTask::~PrimitiveCutMaterialsTask()
{
}

//==================================================
// �J�n
//==================================================
void PrimitiveCutMaterialsTask::start()
{
	printf("�ޗ����������܂�\n");
}

//==================================================
// �X�V
//==================================================
void PrimitiveCutMaterialsTask::update()
{
	printf("�ޗ���؂�\n");
}

//==================================================
// �I��
//==================================================
void PrimitiveCutMaterialsTask::end()
{
	printf("�ޗ���؂�I���܂���\n");
}

//==================================================
// �R�X�g�擾
//==================================================
float PrimitiveCutMaterialsTask::getCost()
{
	return 1;
}

//==================================================
// �v���~�e�B�u�^�X�N���ifalse�͊K�w�^�^�X�N�j
//==================================================
bool PrimitiveCutMaterialsTask::isPrimitive()
{
	return true;
}

//==================================================
// �O�����𖞂����Ă��邩
//==================================================
bool PrimitiveCutMaterialsTask::evaluatePreCondition(HtnState* state)
{
	if (state->haveBeef() && state->haveCarrot() && state->haveOnion() && state->havePtato() && !state->isCutMaterials())
	{
		return true;
	}
	return false;
}

//==================================================
// �X�e�[�^�X��ύX����
//==================================================
void PrimitiveCutMaterialsTask::changeStatus(HtnState* state)
{
	state->setCutMaterials(true);
}

//==================================================
// �^�X�N���I��������
//==================================================
bool PrimitiveCutMaterialsTask::isFinish()
{
	return true;
}
