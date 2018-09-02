#include"stdafx.h"
#include "PrimitiveSimmerTask.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
PrimitiveSimmerTask::PrimitiveSimmerTask()
{
}

//==================================================
// デストラクタ
//==================================================
PrimitiveSimmerTask::~PrimitiveSimmerTask()
{
}

//==================================================
// 開始
//==================================================
void PrimitiveSimmerTask::start()
{
	printf("材料を茹でる準備をします。\n");
}

//==================================================
// 更新
//==================================================
void PrimitiveSimmerTask::update()
{
	printf("材料を茹でます。\n");
}

//==================================================
// 終了
//==================================================
void PrimitiveSimmerTask::end()
{
	printf("茹であがりました。。\n");
}

//==================================================
// コスト取得
//==================================================
float PrimitiveSimmerTask::getCost()
{
	return 1;
}

//==================================================
// プリミティブタスクか（falseは階層型タスク）
//==================================================
bool PrimitiveSimmerTask::isPrimitive()
{
	return true;
}

//==================================================
// 前条件を満たしているか
//==================================================
bool PrimitiveSimmerTask::evaluatePreCondition(HtnState* state)
{
	if (state->isStirFry() && !state->isBoil())
	{
		return true;
	}
	return false;
}

//==================================================
// ステータスを変更する
//==================================================
void PrimitiveSimmerTask::changeStatus(HtnState* state)
{
	state->setsBoil(true);
}

//==================================================
// タスクが終了したか
//==================================================
bool PrimitiveSimmerTask::isFinish()
{
	return true;
}
