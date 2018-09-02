#ifndef _HTN_PLANNER_TASKBASE_H_
#define _HTN_PLANNER_TASKBASE_H_

#include "../../stdafx.h"
#include "State.h"

namespace htn
{
	class TaskBase
	{
	public:
		// コンストラクタ
		TaskBase();

		// デストラクタ
		virtual ~TaskBase();

		// 開始
		virtual void start() = 0;

		// 更新
		virtual void update() = 0;

		// 終了
		virtual void end() = 0;

		// コスト取得
		virtual float getCost() = 0;

		// プリミティブタスクかどうか
		virtual bool isPrimitive() = 0;

		// 前条件を満たしているか
		virtual bool evaluatePreCondition(HtnState* state) = 0;

		// ステータスの変更
		virtual void changeStatus(HtnState* state) = 0;

		// タスクが終了したか
		virtual bool isFinish() = 0;

	private:

	};
}

#endif