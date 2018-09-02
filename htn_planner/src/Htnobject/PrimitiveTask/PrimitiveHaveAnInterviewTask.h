#ifndef _HTN_PRIMITIVETASK_INTERVIEWTASK_H_
#define _HTN_PRIMITIVETASK_INTERVIEWTASK_H_

#include "../../../stdafx.h"
#include "../TaskBase.h"
#include "../State.h"

namespace htn
{
	class PrimitiveHaveAnInterViewTask : public TaskBase
	{
	public:
		PrimitiveHaveAnInterViewTask();
		virtual ~PrimitiveHaveAnInterViewTask();

		virtual void start();
		virtual void update();
		virtual void end();
		virtual float getCost();
		virtual bool isPrimitive();
		virtual bool evaluatePreCondition(HtnState* state);
		virtual void changeStatus(HtnState* state);
		virtual bool isFinish();

		inline void setCost(int cost)
		{
			mCost = cost;
		}
	private:
		int mCost;
	};
}

#endif