#include"stdafx.h"
#include "AstarStateNode.h"

using namespace htn;

//==================================================
// �R���X�g���N�^
//==================================================
AstarStateNode::AstarStateNode()
	: mIsClose(false)
	, mBeforeStateNode(nullptr)
	, mCost(0)
	, mHeuristic(0)
{
}

//==================================================
// �f�X�g���N�^
//==================================================
AstarStateNode::~AstarStateNode()
{
}