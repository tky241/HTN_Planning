#include"stdafx.h"
#include "PrimitiveBuyMaterialsTask.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
PrimitiveBuyMaterialsTask::PrimitiveBuyMaterialsTask()
{
}

//==================================================
// デストラクタ
//==================================================
PrimitiveBuyMaterialsTask::~PrimitiveBuyMaterialsTask()
{
}

//==================================================
// 開始
//==================================================
void PrimitiveBuyMaterialsTask::start()
{
	printf("いまから材料を買いに行きます\n");
}

//==================================================
// 更新
//==================================================
void PrimitiveBuyMaterialsTask::update()
{
	printf("材料を買いました\n");
}

//==================================================
// 終了
//==================================================
void PrimitiveBuyMaterialsTask::end()
{
	printf("家に戻ってきました\n");
}

//==================================================
// コスト取得
//==================================================
float PrimitiveBuyMaterialsTask::getCost()
{
	return 1;
}

//==================================================
// プリミティブタスクか（falseは階層型タスク）
//==================================================
bool PrimitiveBuyMaterialsTask::isPrimitive()
{
	return true;
}

//==================================================
// 前条件を満たしているか
//==================================================
bool PrimitiveBuyMaterialsTask::evaluatePreCondition(HtnState* state)
{
	if (state->haveBeef() && state->haveCarrot() && state->haveOnion() && state->havePtato())
	{
		return false;
	}
	return true;
}

//==================================================
// ステータスを変更する
//==================================================
void PrimitiveBuyMaterialsTask::changeStatus(HtnState* state)
{
	state->setCarrot(true);
	state->setHaveBeef(true);
	state->setHaveOnion(true);
	state->setHavePtato(true);
}

//==================================================
// タスクが終了したか
//==================================================
bool PrimitiveBuyMaterialsTask::isFinish()
{
	return true;
}
