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
		// コンストラクタ
		AstarStateNode();

		// デストラクタ
		virtual ~AstarStateNode();

		// クローズされたか
		inline bool isClose() const
		{
			return mIsClose;
		}

		// クローズの設定
		inline void setClose(bool flg)
		{
			mIsClose = flg;
		}

		// 前回条件の設定（探索終了時にタスクリストを作成するときに使用）
		inline void setBeforStateNode(AstarStateNode* node)
		{
			mBeforeStateNode = node;
		}

		// 前条件を取得（探索終了時にタスクリストを作成するときに使用）
		inline AstarStateNode* getBeforStateNode()
		{
			return mBeforeStateNode;
		}

		// 前のタスクを設定（探索終了時にタスクリストを作成するときに使用）
		inline void setBeforTask(TaskBase* task)
		{
			mBeforeTask = task;
		}

		// 前のタスクを取得（探索終了時にタスクリストを作成するときに使用）
		inline TaskBase* getBeforTask()
		{
			return mBeforeTask;
		}

		// コストの取得
		inline int getCost()
		{
			return mCost;
		}

		// コストの設定
		inline void setCost(int cost)
		{
			mCost = cost;
		}

		// ヒューリスティックの取得
		inline int getHeuristic()
		{
			return mHeuristic;
		}

		// ヒューリスティックの設定
		inline void setHeuristic(int heuristic)
		{
			mHeuristic = heuristic;
		}

		// トータルのコストを取得（コスト＋ヒューリスティック）
		inline int getTotalCost()
		{
			return mCost + mHeuristic;
		}


	private:
		bool mIsClose;		// クローズしているかどうか

		int mCost;
		int mHeuristic;

		TaskBase* mBeforeTask;
		AstarStateNode* mBeforeStateNode;

	};
}

#endif