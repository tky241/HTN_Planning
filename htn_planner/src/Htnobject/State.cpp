#include"stdafx.h"
#include "State.h"

using namespace htn;

HtnState::HtnState()
	: a(false)
	, b(false)
	, c(false)
	, d(false)
{
}


HtnState::~HtnState()
{
}

void HtnState::copyTo(HtnState& state)
{
	state.setA(a);
	state.setB(b);
	state,setC(c);
	state.setD(d);
}

bool HtnState::isSame(HtnState* state)
{
	if (state->getA() != a)
	{
		return false;
	}

	if (state->getB() != b)
	{
		return false;
	}

	if (state->getC() != c)
	{
		return false;
	}

	if (state->getD() != d)
	{
		return false;
	}

	return true;
}