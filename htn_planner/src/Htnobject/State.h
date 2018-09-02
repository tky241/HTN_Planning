#ifndef _HTN_PLANNER_STATE_H_
#define _HTN_PLANNER_STATE_H_

#include "../../stdafx.h"

namespace htn
{
	class HtnState
	{
	public:
		// コンストラクタ
		HtnState();

		// デストラクタ
		virtual ~HtnState();

		// 条件をコピーする
		void copyTo(HtnState& state);

		// 条件が同じかどうか
		bool isSame(HtnState* state);

		// A条件取得
		inline bool getA() const
		{
			return mA;
		}

		// A条件設定
		inline void setA(bool flg)
		{
			mA = flg;
		}

		// B条件取得
		inline bool getB() const
		{
			return mB;
		}

		// B条件設定
		inline void setB(bool flg)
		{
			mB = flg;
		}

		// C条件取得
		inline bool getC() const
		{
			return mC;
		}

		// C条件設定
		inline void setC(bool flg)
		{
			mC = flg;
		}

		// D条件取得
		inline bool getD() const
		{
			return mD;
		}

		// D条件設定
		inline void setD(bool flg)
		{
			mD = flg;
		}

	private:
		bool mA;	// 仮の条件
		bool mB;	// 仮の条件
		bool mC;	// 仮の条件
		bool mD;	// 仮の条件
	};
}

#endif