#include"stdafx.h"
#include "Goal.h"

using namespace htn;

Goal::Goal()
{
}


Goal::~Goal()
{
}

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