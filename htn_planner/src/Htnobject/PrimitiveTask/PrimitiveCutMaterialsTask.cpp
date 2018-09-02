#include"stdafx.h"
#include "PrimitiveCutMaterialsTask.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
PrimitiveCutMaterialsTask::PrimitiveCutMaterialsTask()
{
}

//==================================================
// デストラクタ
//==================================================
PrimitiveCutMaterialsTask::~PrimitiveCutMaterialsTask()
{
}

//==================================================
// 開始
//==================================================
void PrimitiveCutMaterialsTask::start()
{
	printf("材料を準備します\n");
}

//==================================================
// 更新
//==================================================
void PrimitiveCutMaterialsTask::update()
{
	printf("材料を切る\n");
}

//==================================================
// 終了
//==================================================
void PrimitiveCutMaterialsTask::end()
{
	printf("材料を切り終わりました\n");
}

//==================================================
// コスト取得
//==================================================
float PrimitiveCutMaterialsTask::getCost()
{
	return 1;
}

//==================================================
// プリミティブタスクか（falseは階層型タスク）
//==================================================
bool PrimitiveCutMaterialsTask::isPrimitive()
{
	return true;
}

//==================================================
// 前条件を満たしているか
//==================================================
bool PrimitiveCutMaterialsTask::evaluatePreCondition(HtnState* state)
{
	if (state->haveBeef() && state->haveCarrot() && state->haveOnion() && state->havePtato() && !state->isCutMaterials())
	{
		return true;
	}
	return false;
}

//==================================================
// ステータスを変更する
//==================================================
void PrimitiveCutMaterialsTask::changeStatus(HtnState* state)
{
	state->setCutMaterials(true);
}

//==================================================
// タスクが終了したか
//==================================================
bool PrimitiveCutMaterialsTask::isFinish()
{
	return true;
}
