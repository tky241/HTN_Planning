#ifndef _HTN_PLANNER_ASTARSTATENODE_H_
#define _HTN_PLANNER_ASTARSTATENODE_H_

#include "../../stdafx.h"
#include "../Htnobject/State.h"
#include "../Htnobject/TaskBase.h"

namespace htn
{
	class AstarStateNode : public HtnState
	{
	public:
		AstarStateNode();
		virtual ~AstarStateNode();

		inline bool isOpen() const
		{
			return mIsOpen;
		}

		inline void setOpen(bool flg)
		{
			mIsOpen = flg;
		}

		inline bool isClose() const
		{
			return mIsClose;
		}

		inline void setClose(bool flg)
		{
			mIsClose = flg;
		}

		inline void setBeforStateNode(AstarStateNode* node)
		{
			mBeforeStateNode = node;
		}

		inline AstarStateNode* getBeforStateNode()
		{
			return mBeforeStateNode;
		}

		inline void setBeforTask(TaskBase* task)
		{
			mBeforeTask = task;
		}

		inline TaskBase* getBeforTask()
		{
			return mBeforeTask;
		}

		inline int getCost()
		{
			return mCost;
		}

		inline int getHeuristic()
		{
			return mHeuristic;
		}

		inline void setHeuristic(int heuristic)
		{
			mHeuristic = heuristic;
		}

		inline int getTotalCost()
		{
			return mCost + mHeuristic;
		}

		inline void setCost(int cost)
		{
			mCost = cost;
		}

	private:
		bool mIsOpen;
		bool mIsClose;

		int mCost;
		int mHeuristic;

		TaskBase* mBeforeTask;
		AstarStateNode* mBeforeStateNode;

	};
}

#endif