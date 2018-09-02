#include"stdafx.h"
#include "PrimitiveStirFryTask.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
PrimitiveStirFryTask::PrimitiveStirFryTask()
{
}

//==================================================
// デストラクタ
//==================================================
PrimitiveStirFryTask::~PrimitiveStirFryTask()
{
}

//==================================================
// 開始
//==================================================
void PrimitiveStirFryTask::start()
{
	printf("炒め始め\n");
}

//==================================================
// 更新
//==================================================
void PrimitiveStirFryTask::update()
{
	printf("炒める\n");
}

//==================================================
// 終了
//==================================================
void PrimitiveStirFryTask::end()
{
	printf("炒め終わり\n");
}

//==================================================
// コスト取得
//==================================================
float PrimitiveStirFryTask::getCost()
{
	return 1;
}

//==================================================
// プリミティブタスクか（falseは階層型タスク）
//==================================================
bool PrimitiveStirFryTask::isPrimitive()
{
	return true;
}

//==================================================
// 前条件を満たしているか
//==================================================
bool PrimitiveStirFryTask::evaluatePreCondition(HtnState* state)
{
	if (state->isCutMaterials() && !state->isStirFry())
	{
		return true;
	}
	return false;
}

//==================================================
// ステータスを変更する
//==================================================
void PrimitiveStirFryTask::changeStatus(HtnState* state)
{
	state->setStirFry(true);
}

//==================================================
// タスクが終了したか
//==================================================
bool PrimitiveStirFryTask::isFinish()
{
	return true;
}
