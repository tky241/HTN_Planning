#ifndef _HTN_PLANNER_ASTARSTATENODE_H_
#define _HTN_PLANNER_ASTARSTATENODE_H_

#include "../../stdafx.h"
#include "../Htnobject/State.h"
#include "../Htnobject/TaskBase.h"

namespace htn
{
	class AstarStateNode : public HtnState
	{
	public:
		// �R���X�g���N�^
		AstarStateNode();

		// �f�X�g���N�^
		virtual ~AstarStateNode();

		// �N���[�Y���ꂽ��
		inline bool isClose() const
		{
			return mIsClose;
		}

		// �N���[�Y�̐ݒ�
		inline void setClose(bool flg)
		{
			mIsClose = flg;
		}

		// �O������̐ݒ�i�T���I�����Ƀ^�X�N���X�g���쐬����Ƃ��Ɏg�p�j
		inline void setBeforStateNode(AstarStateNode* node)
		{
			mBeforeStateNode = node;
		}

		// �O�������擾�i�T���I�����Ƀ^�X�N���X�g���쐬����Ƃ��Ɏg�p�j
		inline AstarStateNode* getBeforStateNode()
		{
			return mBeforeStateNode;
		}

		// �O�̃^�X�N��ݒ�i�T���I�����Ƀ^�X�N���X�g���쐬����Ƃ��Ɏg�p�j
		inline void setBeforTask(TaskBase* task)
		{
			mBeforeTask = task;
		}

		// �O�̃^�X�N���擾�i�T���I�����Ƀ^�X�N���X�g���쐬����Ƃ��Ɏg�p�j
		inline TaskBase* getBeforTask()
		{
			return mBeforeTask;
		}

		// �R�X�g�̎擾
		inline int getCost()
		{
			return mCost;
		}

		// �R�X�g�̐ݒ�
		inline void setCost(int cost)
		{
			mCost = cost;
		}

		// �q���[���X�e�B�b�N�̎擾
		inline int getHeuristic()
		{
			return mHeuristic;
		}

		// �q���[���X�e�B�b�N�̐ݒ�
		inline void setHeuristic(int heuristic)
		{
			mHeuristic = heuristic;
		}

		// �g�[�^���̃R�X�g���擾�i�R�X�g�{�q���[���X�e�B�b�N�j
		inline int getTotalCost()
		{
			return mCost + mHeuristic;
		}


	private:
		bool mIsClose;		// �N���[�Y���Ă��邩�ǂ���

		int mCost;
		int mHeuristic;

		TaskBase* mBeforeTask;
		AstarStateNode* mBeforeStateNode;

	};
}

#endif