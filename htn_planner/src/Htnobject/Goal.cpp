#include"stdafx.h"
#include "Goal.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
Goal::Goal()
{
}

//==================================================
// デストラクタ
//==================================================
Goal::~Goal()
{
}

//==================================================
// 評価（戻り値はゴールからどれくらい離れているかの数値）
//==================================================
int htn::Goal::evaluate(HtnState * state)
{
	int heuristic = 0;

	if (!state->havePtato())
	{
		heuristic++;
	}

	if (!state->haveCarrot())
	{
		heuristic++;
	}

	if (!state->haveOnion())
	{
		heuristic++;
	}

	if (!state->haveBeef())
	{
		heuristic++;
	}

	if (!state->isCutMaterials())
	{
		heuristic++;
	}

	if (!state->isStirFry())
	{
		heuristic++;
	}

	if (!state->isBoil())
	{
		heuristic++;
	}
	if (!state->isPutRoux())
	{
		heuristic++;
	}

	if (state->isCurry())
	{
		return 0;
	}


	return heuristic;
}