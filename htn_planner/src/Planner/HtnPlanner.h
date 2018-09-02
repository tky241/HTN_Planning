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
		// コンストラクタ
		HtnPlanner();

		// デストラクタ
		virtual ~HtnPlanner();

		// ドメインにタスクを登録する
		void registerDomain(TaskBase* task);

		// 実行するタスクを登録する
		void registerTask(TaskBase* task);

		// 探索に使用するステートを登録する
		void registerState(AstarStateNode* node);

		//タスクをクリアする
		inline void clearTask()
		{
			mTaskCount = 0;
		}

		// 初期設定
		void setup();

		// プランニングを行う
		void plan(HtnState* state, Goal* goal);

		// 検索に使用する状態がすべてCloseしているか
		bool isAllStateClose();

		// 同じ条件のノードがあれば返す
		AstarStateNode* haveSameNode(AstarStateNode* node);

		// コストが最小のノードを返す
		AstarStateNode* pickMinCostNode();

		// タスクの実行を行う（falseを返せば終了）
		bool updateTask();

		// 次のタスクに切り替える
		bool nextTask();

	private:
		TaskBase* mDomain[1024];				// ドメイン
		unsigned int mDomainCount;				// ドメイン数

		TaskBase* mTasks[1024];					// タスク
		unsigned int mTaskCount;				// タスク数

		AstarStateNode* mPlanStates[1024];		// プラン
		unsigned int mPlanstateCount;			// プラン数

		int mCurrentTaskNo;						// 現在のタスク番号
		bool mIsCallTaskStart;					// タスクのスタートを呼ぶか
	};
}

#endif