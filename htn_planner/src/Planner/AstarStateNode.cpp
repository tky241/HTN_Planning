#include"stdafx.h"
#include "AstarStateNode.h"

using namespace htn;

AstarStateNode::AstarStateNode()
	: mIsClose(false)
	, mIsOpen(false)
	, mBeforeStateNode(nullptr)
{
}


AstarStateNode::~AstarStateNode()
{
}