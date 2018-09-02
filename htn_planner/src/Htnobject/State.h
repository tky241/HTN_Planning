#ifndef _HTN_PLANNER_STATE_H_
#define _HTN_PLANNER_STATE_H_

#include "../../stdafx.h"

namespace htn
{
	class HtnState
	{
	public:
		// �R���X�g���N�^
		HtnState();

		// �f�X�g���N�^
		virtual ~HtnState();

		// �������R�s�[����
		void copyTo(HtnState& state);

		// �������������ǂ���
		bool isSame(HtnState* state);


		// �l�Q�������Ă��邩
		inline bool haveCarrot() const
		{
			return mHaveCarrot;
		}

		// �l�Q�ݒ�
		inline void setCarrot(bool flg)
		{
			mHaveCarrot = flg;
		}

		// �W���K�C�������Ă��邩
		inline bool havePtato() const
		{
			return mHavePtato;
		}

		// �W���K�C���ݒ�
		inline void setHavePtato(bool flg)
		{
			mHavePtato = flg;
		}

		// �ʂ˂������Ă��邩
		inline bool haveOnion() const
		{
			return mHaveOnion;
		}

		// �ʂ˂��ݒ�
		inline void setHaveOnion(bool flg)
		{
			mHaveOnion = flg;
		}

		// ���������Ă��邩
		inline bool haveBeef() const
		{
			return mHaveBeef;
		}

		// �����ݒ�
		inline void setHaveBeef(bool flg)
		{
			mHaveBeef = flg;
		}

		// �ޗ����؂��Ă��邩
		inline bool isCutMaterials() const
		{
			return mIsCutMaterials;
		}

		// �ޗ����؂��Ă��邩
		inline void setCutMaterials(bool flg)
		{
			mIsCutMaterials = flg;
		}

		// �ޗ����u�߂��Ă��邩
		inline bool isStirFry() const
		{
			return mIsStirFry;
		}

		// �ޗ����u�߂��Ă��邩
		inline void setStirFry(bool flg)
		{
			mIsStirFry = flg;
		}

		// �ޗ���䥂ł��Ă��邩
		inline bool isBoil() const
		{
			return mIsBoil;
		}

		// �ޗ���䥂ł��Ă��邩
		inline void setsBoil(bool flg)
		{
			mIsBoil = flg;
		}

		// ���[�������Ă��邩
		inline bool isPutRoux() const
		{
			return mIsPutRoux;
		}

		// ���[�������Ă��邩
		inline void setPutRoux(bool flg)
		{
			mIsPutRoux = flg;
		}

		// �o���オ�����J���[�����邩
		inline bool isCurry() const
		{
			return mIsCurry;
		}

		// �o���オ�����J���[�����邩
		inline void setCurry(bool flg)
		{
			mIsCurry = flg;
		}

		// �������̎擾
		inline int getMoney() const
		{
			return mMoney;
		}

		// �������ݒ�
		inline void setMoney(int money)
		{
			mMoney = money;
		}

	private:
		bool mHaveCarrot;
		bool mHavePtato;
		bool mHaveOnion;
		bool mHaveBeef;

		bool mIsCutMaterials;
		bool mIsStirFry;
		bool mIsBoil;
		bool mIsPutRoux;

		bool mIsCurry;

		int mMoney;
	};
}

#endif