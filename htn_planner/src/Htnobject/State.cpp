#include"stdafx.h"
#include "State.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
HtnState::HtnState()
	: mA(false)
	, mB(false)
	, mC(false)
	, mD(false)
{
}

//==================================================
// �f�X�g���N�^
//==================================================
HtnState::~HtnState()
{
}

//==================================================
// �����̃X�e�[�g�ɏ������R�s�[
//==================================================
void HtnState::copyTo(HtnState& state)
{
	state.setA(mA);
	state.setB(mB);
	state,setC(mC);
	state.setD(mD);
}

//==================================================
// ���������ꂩ�ǂ���
//==================================================
bool HtnState::isSame(HtnState* state)
{
	if (state->getA() != mA)
	{
		return false;
	}

	if (state->getB() != mB)
	{
		return false;
	}

	if (state->getC() != mC)
	{
		return false;
	}

	if (state->getD() != mD)
	{
		return false;
	}

	return true;
}