#include"stdafx.h"
#include "PrimitiveGoTask.h"

using namespace htn;

PrimitiveGoTask::PrimitiveGoTask()
	: mCost(0)
{
}


PrimitiveGoTask::~PrimitiveGoTask()
{
}

void PrimitiveGoTask::start()
{
	printf("GoStart\n");
}

void PrimitiveGoTask::update()
{
	printf("-----------------\nGOOOOOO!!!%d\n-----------------\n",mCost);
}

void PrimitiveGoTask::end()
{
	printf("GoEndt\n");
}

float PrimitiveGoTask::getCost()
{
	return 1;
}

bool PrimitiveGoTask::isPrimitive()
{
	return true;
}

bool PrimitiveGoTask::evaluatePreCondition(HtnState* state)
{
	if (!state->getA())
	{
		return true;
	}
	return false;
}

void PrimitiveGoTask::changeStatus(HtnState* state)
{

	state->setA(true);
}

bool PrimitiveGoTask::isFinish()
{
	return true;
}
