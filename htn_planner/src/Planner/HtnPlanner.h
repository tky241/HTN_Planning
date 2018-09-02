#ifndef _HTN_PLANNER_PLANNER_H_
#define _HTN_PLANNER_PLANNER_H_

#include "../../stdafx.h"
#include "../Htnobject/State.h"
#include "../Htnobject/TaskBase.h"
#include "../Htnobject/Goal.h"
#include "AstarStateNode.h"

namespace htn
{
	class HtnPlanner
	{
	public:
		// �R���X�g���N�^
		HtnPlanner();

		// �f�X�g���N�^
		virtual ~HtnPlanner();

		void registerDomain(TaskBase* task);
		void registerTask(TaskBase* task);
		void registerState(AstarStateNode* node);

		inline void clearTask()
		{
			mTaskCount = 0;
		}

		void setup();

		void plan(HtnState* state, Goal* goal);

		bool isAllStateClose();

		AstarStateNode* haveSameNode(AstarStateNode* node);

		AstarStateNode* pickMinCostNode();

		bool updateTask();
		bool nextTask();

	private:
		TaskBase* mDomain[1024];			// �^�X�N��
		unsigned int mDomainCount;

		TaskBase* mTasks[1024];
		unsigned int mTaskCount;

		AstarStateNode* mPlanStates[1024];
		unsigned int mPlanstateCount;

		int mCurrentTaskNo;
		bool mIsCallTaskStart;
	};
}

#endif