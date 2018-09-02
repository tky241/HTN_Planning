#include"stdafx.h"
#include "AstarStateNode.h"

using namespace htn;

AstarStateNode::AstarStateNode()
	: mIsClose(false)
	, mIsOpen(false)
	, mBeforeStateNode(nullptr)
	, mCost(0)
	, mHeuristic(0)
{
}


AstarStateNode::~AstarStateNode()
{
}