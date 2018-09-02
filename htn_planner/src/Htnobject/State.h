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

		// A�����擾
		inline bool getA() const
		{
			return mA;
		}

		// A�����ݒ�
		inline void setA(bool flg)
		{
			mA = flg;
		}

		// B�����擾
		inline bool getB() const
		{
			return mB;
		}

		// B�����ݒ�
		inline void setB(bool flg)
		{
			mB = flg;
		}

		// C�����擾
		inline bool getC() const
		{
			return mC;
		}

		// C�����ݒ�
		inline void setC(bool flg)
		{
			mC = flg;
		}

		// D�����擾
		inline bool getD() const
		{
			return mD;
		}

		// D�����ݒ�
		inline void setD(bool flg)
		{
			mD = flg;
		}

	private:
		bool mA;	// ���̏���
		bool mB;	// ���̏���
		bool mC;	// ���̏���
		bool mD;	// ���̏���
	};
}

#endif