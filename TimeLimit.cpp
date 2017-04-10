/**********************************************************************
// @param	�uTimeLimit�v�N���X�̃\�[�X�t�@�C��
// @create	����T��
// @date	17/01/19
**********************************************************************/

// �w�b�_�t�@�C���̃C���N���[�h
#include "TimeLimit.h"

USING_NS_CC;

// �����o�֐��̒�`

// �����ݒ�
bool TimeLimit::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

// �J�E���g�_�E��
void TimeLimit::timeCountDown(int* frame, int* time)
{
	(*frame)++;
	if (*frame >= NUM_SECOND)
	{
		(*time)--;
		(*frame) = 0;
	}
}

// ���Ԃ̕`��
void TimeLimit::timeDraw(Sprite* timeSpr, int time)
{
	timeSpr->setTextureRect(Rect{ time * 128.0f, 0.0f, 128.0f, 128.0f });
}