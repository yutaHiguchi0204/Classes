/* =====================================================================
//! @param		�uGage�v�N���X�̃w�b�_�t�@�C��
//! @create		����@�T��
//! @date		17/04/07
===================================================================== */
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include "cocos2d.h"

// �N���X�̒�`
class Gage : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Gage);
	virtual bool init();

	void SetGage(int fullPoint);		// �Q�[�W�̃Z�b�g
};