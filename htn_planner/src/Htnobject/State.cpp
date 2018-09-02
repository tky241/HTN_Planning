#include"stdafx.h"
#include "State.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
HtnState::HtnState()
	: mHaveCarrot(false)
	, mHavePtato(false)
	, mHaveOnion(false)
	, mHaveBeef(false)
	, mIsCutMaterials(false)
	, mIsStirFry(false)
	, mIsBoil(false)
	, mIsPutRoux(false)
	, mIsCurry(false)
	, mMoney(0)
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
	state.setCarrot(mHaveCarrot);
	state.setHavePtato(mHavePtato);
	state.setHaveOnion(mHaveOnion);
	state.setHaveBeef(mHaveBeef);

	state.setCutMaterials(mIsCutMaterials);
	state.setStirFry(mIsStirFry);
	state.setsBoil(mIsBoil);
	state.setPutRoux(mIsPutRoux);
	state.setCurry(mIsCurry);

	state.setMoney(mMoney);
}

//==================================================
// 条件が同一かどうか
//==================================================
bool HtnState::isSame(HtnState* state)
{
	if (state->haveCarrot() != mHaveCarrot)
	{
		return false;
	}

	if (state->haveOnion() != mHaveOnion)
	{
		return false;
	}

	if (state->havePtato() != mHavePtato)
	{
		return false;
	}

	if (state->haveBeef() != mHaveBeef)
	{
		return false;
	}

	if (state->isCutMaterials() != mIsCutMaterials)
	{
		return false;
	}

	if (state->isStirFry() != mIsStirFry)
	{
		return false;
	}

	if (state->isBoil() != mIsBoil)
	{
		return false;
	}

	if (state->isPutRoux() != mIsPutRoux)
	{
		return false;
	}

	if (state->isCurry() != mIsCurry)
	{
		return false;
	}

	if (state->getMoney() != mMoney)
	{
		return false;
	}

	return true;
}