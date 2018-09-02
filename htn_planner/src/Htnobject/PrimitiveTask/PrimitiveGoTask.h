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
		// コンストラクタ
		PrimitiveGoTask();

		// デストラクタ
		virtual ~PrimitiveGoTask();

		// 開始処理
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

		// タスクが終了しているか
		virtual bool isFinish();

	};
}

#endif