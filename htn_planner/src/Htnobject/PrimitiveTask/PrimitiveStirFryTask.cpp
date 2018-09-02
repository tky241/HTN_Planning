#include"stdafx.h"
#include "PrimitiveStirFryTask.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
PrimitiveStirFryTask::PrimitiveStirFryTask()
{
}

//==================================================
// �f�X�g���N�^
//==================================================
PrimitiveStirFryTask::~PrimitiveStirFryTask()
{
}

//==================================================
// �J�n
//==================================================
void PrimitiveStirFryTask::start()
{
	printf("�u�ߎn��\n");
}

//==================================================
// �X�V
//==================================================
void PrimitiveStirFryTask::update()
{
	printf("�u�߂�\n");
}

//==================================================
// �I��
//==================================================
void PrimitiveStirFryTask::end()
{
	printf("�u�ߏI���\n");
}

//==================================================
// �R�X�g�擾
//==================================================
float PrimitiveStirFryTask::getCost()
{
	return 1;
}

//==================================================
// �v���~�e�B�u�^�X�N���ifalse�͊K�w�^�^�X�N�j
//==================================================
bool PrimitiveStirFryTask::isPrimitive()
{
	return true;
}

//==================================================
// �O�����𖞂����Ă��邩
//==================================================
bool PrimitiveStirFryTask::evaluatePreCondition(HtnState* state)
{
	if (state->isCutMaterials() && !state->isStirFry())
	{
		return true;
	}
	return false;
}

//==================================================
// �X�e�[�^�X��ύX����
//==================================================
void PrimitiveStirFryTask::changeStatus(HtnState* state)
{
	state->setStirFry(true);
}

//==================================================
// �^�X�N���I��������
//==================================================
bool PrimitiveStirFryTask::isFinish()
{
	return true;
}
