/* =====================================================================
//! @param		�uHuman�v�N���X�̃w�b�_�t�@�C��
//! @create		����@�T��
//! @date		17/04/07
===================================================================== */
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include "cocos2d.h"

// �萔
const int MAX_FULLPOINT = 100;			// �ő喞���x

// �N���X�̒�`
class Human : public cocos2d::Layer
{
private:
	int m_fullPoint;					// �����̒��܂�

public:
	CREATE_FUNC(Human);
	virtual bool init();

	void SetFullPoint(int point);		// �����x��ݒ�
	int GetFullPoint();					// �����x���擾
};