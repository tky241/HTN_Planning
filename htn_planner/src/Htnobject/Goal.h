#ifndef _HTN_PLANNER_GOAL_H_
#define _HTN_PLANNER_GOAL_H_

#include "../../stdafx.h"
#include "State.h"

namespace htn
{
	class Goal
	{
	public:
		// �R���X�g���N�^
		Goal();

		// �f�X�g���N�^
		virtual ~Goal();

		// �S�[�������𖞂����Ă��邩
		int evaluate(HtnState* state);
	private:

	};
}
#endif