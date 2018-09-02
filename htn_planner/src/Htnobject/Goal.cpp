#include"stdafx.h"
#include "Goal.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
Goal::Goal()
{
}

//==================================================
// �f�X�g���N�^
//==================================================
Goal::~Goal()
{
}

//==================================================
// �]���i�߂�l�̓S�[������ǂꂭ�炢����Ă��邩�̐��l�j
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