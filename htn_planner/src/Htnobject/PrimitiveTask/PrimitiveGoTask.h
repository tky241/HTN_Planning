#ifndef _HTN_PRIMITIVETASK_GOTASK_H_
#define _HTN_PRIMITIVETASK_GOTASK_H_

#include "../../../stdafx.h"
#include "../TaskBase.h"
#include "../State.h"

namespace htn
{
	class PrimitiveGoTask : public TaskBase
	{
	public:
		PrimitiveGoTask();
		virtual ~PrimitiveGoTask();

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