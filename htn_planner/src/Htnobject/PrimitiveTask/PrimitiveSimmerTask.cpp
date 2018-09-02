#include"stdafx.h"
#include "PrimitiveSimmerTask.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
PrimitiveSimmerTask::PrimitiveSimmerTask()
{
}

//==================================================
// �f�X�g���N�^
//==================================================
PrimitiveSimmerTask::~PrimitiveSimmerTask()
{
}

//==================================================
// �J�n
//==================================================
void PrimitiveSimmerTask::start()
{
	printf("�ޗ���䥂ł鏀�������܂��B\n");
}

//==================================================
// �X�V
//==================================================
void PrimitiveSimmerTask::update()
{
	printf("�ޗ���䥂ł܂��B\n");
}

//==================================================
// �I��
//==================================================
void PrimitiveSimmerTask::end()
{
	printf("䥂ł�����܂����B�B\n");
}

//==================================================
// �R�X�g�擾
//==================================================
float PrimitiveSimmerTask::getCost()
{
	return 1;
}

//==================================================
// �v���~�e�B�u�^�X�N���ifalse�͊K�w�^�^�X�N�j
//==================================================
bool PrimitiveSimmerTask::isPrimitive()
{
	return true;
}

//==================================================
// �O�����𖞂����Ă��邩
//==================================================
bool PrimitiveSimmerTask::evaluatePreCondition(HtnState* state)
{
	if (state->isStirFry() && !state->isBoil())
	{
		return true;
	}
	return false;
}

//==================================================
// �X�e�[�^�X��ύX����
//==================================================
void PrimitiveSimmerTask::changeStatus(HtnState* state)
{
	state->setsBoil(true);
}

//==================================================
// �^�X�N���I��������
//==================================================
bool PrimitiveSimmerTask::isFinish()
{
	return true;
}
