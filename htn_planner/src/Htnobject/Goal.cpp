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