#ifndef _HTN_PLANNER_GOAL_H_
#define _HTN_PLANNER_GOAL_H_

#include "../../stdafx.h"
#include "State.h"

namespace htn
{
	class Goal
	{
	public:
		Goal();
		virtual ~Goal();

		int evaluate(HtnState* state);
	private:

	};
}
#endif