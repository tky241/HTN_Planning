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

	if (!state->getA())
	{
		heuristic++;
	}

	if (!state->getB())
	{
		heuristic++;
	}

	if (state->getC())
	{
		heuristic++;
	}

	if (state->getD())
	{
		heuristic++;
	}

	return heuristic;
}