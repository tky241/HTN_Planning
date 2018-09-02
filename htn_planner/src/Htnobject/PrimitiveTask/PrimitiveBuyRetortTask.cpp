#include"stdafx.h"
#include "PrimitiveBuyRetortTask.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
PrimitiveBuyRetortTask::PrimitiveBuyRetortTask()
{
}

//==================================================
// デストラクタ
//==================================================
PrimitiveBuyRetortTask::~PrimitiveBuyRetortTask()
{
}

//==================================================
// 開始
//==================================================
void PrimitiveBuyRetortTask::start()
{
	printf("レトルトカレーを買いに行きます\n");
}

//==================================================
// 更新
//==================================================
void PrimitiveBuyRetortTask::update()
{
	printf("レトルトカレーを買う。1000円消費しました。\n");
}

//==================================================
// 終了
//==================================================
void PrimitiveBuyRetortTask::end()
{
	printf("家に戻ります。\n");
}

//==================================================
// コスト取得
//==================================================
float PrimitiveBuyRetortTask::getCost()
{
	return 1;
}

//==================================================
// プリミティブタスクか（falseは階層型タスク）
//==================================================
bool PrimitiveBuyRetortTask::isPrimitive()
{
	return true;
}

//==================================================
// 前条件を満たしているか
//==================================================
bool PrimitiveBuyRetortTask::evaluatePreCondition(HtnState* state)
{
	if (state->getMoney() > 1000)
	{
		return true;
	}
	return false;
}

//==================================================
// ステータスを変更する
//==================================================
void PrimitiveBuyRetortTask::changeStatus(HtnState* state)
{
	state->setMoney(state->getMoney() - 1000);
	state->setCurry(true);
}

//==================================================
// タスクが終了したか
//==================================================
bool PrimitiveBuyRetortTask::isFinish()
{
	return true;
}
