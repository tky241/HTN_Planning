// htn_planner.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "src\Htnobject\State.h"
#include "src\Planner\HtnPlanner.h"

#include "crtdbg.h"
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	htn::HtnPlanner* planner = new htn::HtnPlanner();
	planner->setup();
	htn::HtnState* state = new htn::HtnState();
	htn::Goal* goal = new htn::Goal();

	planner->plan(state, goal);

	while (planner->updateTask());

	delete planner;
	delete state;
	delete goal;
}

