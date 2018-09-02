#ifndef _HTN_PRIMITIVETASK_PRIMITIVESIMMERTASK_H_
#define _HTN_PRIMITIVETASK_PRIMITIVESIMMERTASK_H_

#include "../../../stdafx.h"
#include "../TaskBase.h"
#include "../State.h"

namespace htn
{
	class PrimitiveSimmerTask : public TaskBase
	{
	public:
		// コンストラクタ
		PrimitiveSimmerTask();

		// デストラクタ
		virtual ~PrimitiveSimmerTask();

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