#ifndef _HTN_PLANNER_STATE_H_
#define _HTN_PLANNER_STATE_H_

#include "../../stdafx.h"

namespace htn
{
	class HtnState
	{
	public:
		HtnState();
		virtual ~HtnState();

		void copyTo(HtnState& state);

		bool isSame(HtnState* state);

		inline bool getA() const
		{
			return a;
		}

		inline void setA(bool flg)
		{
			a = flg;
		}

		inline bool getB() const
		{
			return b;
		}

		inline void setB(bool flg)
		{
			b = flg;
		}

		inline bool getC() const
		{
			return c;
		}

		inline void setC(bool flg)
		{
			c = flg;
		}

		inline bool getD() const
		{
			return d;
		}

		inline void setD(bool flg)
		{
			d = flg;
		}

	private:
		bool a;
		bool b;
		bool c;
		bool d;
	};
}

#endif