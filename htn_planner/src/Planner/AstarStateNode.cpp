#include"stdafx.h"
#include "AstarStateNode.h"

using namespace htn;

//==================================================
// コンストラクタ
//==================================================
AstarStateNode::AstarStateNode()
	: mIsClose(false)
	, mBeforeStateNode(nullptr)
	, mCost(0)
	, mHeuristic(0)
{
}

//==================================================
// デストラクタ
//==================================================
AstarStateNode::~AstarStateNode()
{
}