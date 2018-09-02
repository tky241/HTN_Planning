#include"stdafx.h"
#include "PrimitiveHaveAnInterViewTask.h"

using namespace htn;

PrimitiveHaveAnInterViewTask::PrimitiveHaveAnInterViewTask()
	: mCost(0)
{
}


PrimitiveHaveAnInterViewTask::~PrimitiveHaveAnInterViewTask()
{
}

void PrimitiveHaveAnInterViewTask::start()
{
	printf("InterviewStart\n");
}

void PrimitiveHaveAnInterViewTask::update()
{
	printf("-----------------\nInterView!!!%d\n-----------------\n", mCost);
}

void PrimitiveHaveAnInterViewTask::end()
{
	printf("InterviewEndt\n");
}

float PrimitiveHaveAnInterViewTask::getCost()
{
	return mCost;
}

bool PrimitiveHaveAnInterViewTask::isPrimitive()
{
	return true;
}

bool PrimitiveHaveAnInterViewTask::evaluatePreCondition(HtnState* state)
{
	if (!state->getB())
	{
		return true;
	}
	return false;
}

void PrimitiveHaveAnInterViewTask::changeStatus(HtnState* state)
{
	state->setB(true);
}

bool PrimitiveHaveAnInterViewTask::isFinish()
{
	return true;
}
