/**********************************************************************
// @param	�uTimeLimit�v�N���X�̃w�b�_�t�@�C��
// @create	����T��
// @date	17/01/19
**********************************************************************/
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include "cocos2d.h"

// �萔
const int NUM_SECOND = 60;		// ��b

// �N���X�̒�`
class TimeLimit : public cocos2d::Layer
{
public:
	virtual bool init();
	
	CREATE_FUNC(TimeLimit);

	static void timeCountDown(int* frame, int* time);				// �J�E���g�_�E��
	
	static void timeDraw(cocos2d::Sprite* timeSpr, int time);		// ���Ԃ̕`��
};