#ifndef _HTN_PLANNER_TASKBASE_H_
#define _HTN_PLANNER_TASKBASE_H_

#include "../../stdafx.h"
#include "State.h"

namespace htn
{
	class TaskBase
	{
	public:
		TaskBase();
		virtual ~TaskBase();

		virtual void start() = 0;
		virtual void update() = 0;
		virtual void end() = 0;
		virtual float getCost() = 0;
		virtual bool isPrimitive() = 0;
		virtual bool evaluatePreCondition(HtnState* state) = 0;
		virtual void changeStatus(HtnState* state) = 0;
		virtual bool isFinish() = 0;

	private:

	};
}

#endif