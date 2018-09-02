#include"stdafx.h"
#include "PrimitiveHaveAnInterViewTask.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
PrimitiveHaveAnInterViewTask::PrimitiveHaveAnInterViewTask()
	: mCost(0)
{
}


//==================================================
// デストラクタ
//==================================================
PrimitiveHaveAnInterViewTask::~PrimitiveHaveAnInterViewTask()
{
}

//==================================================
// 開始
//==================================================
void PrimitiveHaveAnInterViewTask::start()
{
	printf("InterviewStart\n");
}

//==================================================
// 更新
//==================================================
void PrimitiveHaveAnInterViewTask::update()
{
	printf("-----------------\nInterView!!!%d\n-----------------\n", mCost);
}

//==================================================
// 終了
//==================================================
void PrimitiveHaveAnInterViewTask::end()
{
	printf("InterviewEndt\n");
}

//==================================================
// コスト取得
//==================================================
float PrimitiveHaveAnInterViewTask::getCost()
{
	return mCost;
}

//==================================================
// プリミティブタスクか
//==================================================
bool PrimitiveHaveAnInterViewTask::isPrimitive()
{
	return true;
}

//==================================================
// 前条件を満たしているか
//==================================================
bool PrimitiveHaveAnInterViewTask::evaluatePreCondition(HtnState* state)
{
	if (!state->getB())
	{
		return true;
	}
	return false;
}

//==================================================
// ステータス変更を反映する
//==================================================
void PrimitiveHaveAnInterViewTask::changeStatus(HtnState* state)
{
	state->setB(true);
}

//==================================================
// タスクが終了したか
//==================================================
bool PrimitiveHaveAnInterViewTask::isFinish()
{
	return true;
}
