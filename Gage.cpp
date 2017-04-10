/* =====================================================================
//! @param		�uGage�v�N���X�̃\�[�X�t�@�C��
//! @create		����@�T��
//! @date		17/04/07
===================================================================== */

// �w�b�_�t�@�C���̃C���N���[�h
#include "Gage.h"
#include "Human.h"

// ���O���
USING_NS_CC;

// �����o�֐��̒�`

// �����ݒ�
bool Gage::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	setTexture("gage.png");
	setAnchorPoint(Vec2(0, 0));
	setScaleY(0);

	return true;
}

/* =====================================================================
//! ���@�e		�Q�[�W�ݒ�
//! ���@��		�����x�iint�j
//! �߂�l		�Ȃ�
===================================================================== */
void Gage::SetGage(int fullPoint)
{
	setScaleY(static_cast<float>(fullPoint) / MAX_FULLPOINT);
}