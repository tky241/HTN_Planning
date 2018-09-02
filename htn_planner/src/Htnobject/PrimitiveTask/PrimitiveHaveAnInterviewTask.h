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
		// コンストラクタ
		PrimitiveHaveAnInterViewTask();

		// デストラクタ
		virtual ~PrimitiveHaveAnInterViewTask();

		// 開始
		virtual void start();

		// 更新
		virtual void update();

		// 終了
		virtual void end();

		// コスト取得
		virtual float getCost();

		// プリミティブタスクかどうか
		virtual bool isPrimitive();

		// 前条件を満たしているか
		virtual bool evaluatePreCondition(HtnState* state);

		// ステータスの変更
		virtual void changeStatus(HtnState* state);

		// タスクが終了したか
		virtual bool isFinish();

		// コストの設定（外部からコストを操作して動作を確認する用）
		inline void setCost(int cost)
		{
			mCost = cost;
		}
	private:
		int mCost;
	};
}

#endif