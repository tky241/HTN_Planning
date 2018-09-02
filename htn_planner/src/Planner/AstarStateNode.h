#ifndef _HTN_PLANNER_ASTARSTATENODE_H_
#define _HTN_PLANNER_ASTARSTATENODE_H_

#include "../../stdafx.h"
#include "../Htnobject/State.h"

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

		inline void seClose(bool flg)
		{
			mIsClose = flg;
		}

		inline void setBeforStateNode(AstarStateNode* node)
		{
			mBeforeStateNode = node;
		}

	private:
		bool mIsOpen;
		bool mIsClose;

		AstarStateNode* mBeforeStateNode;

	};
}

#endif