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


		// 人参を持っているか
		inline bool haveCarrot() const
		{
			return mHaveCarrot;
		}

		// 人参設定
		inline void setCarrot(bool flg)
		{
			mHaveCarrot = flg;
		}

		// ジャガイモ持っているか
		inline bool havePtato() const
		{
			return mHavePtato;
		}

		// ジャガイモ設定
		inline void setHavePtato(bool flg)
		{
			mHavePtato = flg;
		}

		// 玉ねぎ持っているか
		inline bool haveOnion() const
		{
			return mHaveOnion;
		}

		// 玉ねぎ設定
		inline void setHaveOnion(bool flg)
		{
			mHaveOnion = flg;
		}

		// 牛肉持っているか
		inline bool haveBeef() const
		{
			return mHaveBeef;
		}

		// 牛肉設定
		inline void setHaveBeef(bool flg)
		{
			mHaveBeef = flg;
		}

		// 材料が切られているか
		inline bool isCutMaterials() const
		{
			return mIsCutMaterials;
		}

		// 材料が切られているか
		inline void setCutMaterials(bool flg)
		{
			mIsCutMaterials = flg;
		}

		// 材料が炒められているか
		inline bool isStirFry() const
		{
			return mIsStirFry;
		}

		// 材料が炒められているか
		inline void setStirFry(bool flg)
		{
			mIsStirFry = flg;
		}

		// 材料が茹でられているか
		inline bool isBoil() const
		{
			return mIsBoil;
		}

		// 材料が茹でられているか
		inline void setsBoil(bool flg)
		{
			mIsBoil = flg;
		}

		// ルーが入っているか
		inline bool isPutRoux() const
		{
			return mIsPutRoux;
		}

		// ルーが入っているか
		inline void setPutRoux(bool flg)
		{
			mIsPutRoux = flg;
		}

		// 出来上がったカレーがあるか
		inline bool isCurry() const
		{
			return mIsCurry;
		}

		// 出来上がったカレーがあるか
		inline void setCurry(bool flg)
		{
			mIsCurry = flg;
		}

		// 所持金の取得
		inline int getMoney() const
		{
			return mMoney;
		}

		// 所持金設定
		inline void setMoney(int money)
		{
			mMoney = money;
		}

	private:
		bool mHaveCarrot;
		bool mHavePtato;
		bool mHaveOnion;
		bool mHaveBeef;

		bool mIsCutMaterials;
		bool mIsStirFry;
		bool mIsBoil;
		bool mIsPutRoux;

		bool mIsCurry;

		int mMoney;
	};
}

#endif