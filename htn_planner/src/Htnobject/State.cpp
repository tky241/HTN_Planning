#include"stdafx.h"
#include "State.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
HtnState::HtnState()
	: mA(false)
	, mB(false)
	, mC(false)
	, mD(false)
{
}

//==================================================
// デストラクタ
//==================================================
HtnState::~HtnState()
{
}

//==================================================
// 引数のステートに条件をコピー
//==================================================
void HtnState::copyTo(HtnState& state)
{
	state.setA(mA);
	state.setB(mB);
	state,setC(mC);
	state.setD(mD);
}

//==================================================
// 条件が同一かどうか
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