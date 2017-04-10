/* =====================================================================
//! @param		�uPlayScene�v�N���X�̃w�b�_�t�@�C��
//! @create		����@�T��
//! @date		17/04/07
===================================================================== */
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include "cocos2d.h"
#include "Gage.h"
#include "Human.h"
#include "Player.h"

// �萔
const int WINDOW_WIDTH = 960;						// ��ʂ̕�
const int WINDOW_HEIGHT = 640;						// ��ʂ̍���
const int NUM_SECOND = 60;							// �P�b
const int INTERVAL_FOOD = NUM_SECOND * 2;			// �H�ނ������Ă���Ԋu

// �N���X�̒�`
class PlayScene : public cocos2d::Scene
{
private:
	cocos2d::Sprite* m_pBack;			// �w�i
	cocos2d::Sprite* m_pStomach;		// ��

	Human* m_pHuman;					// �l��

	Gage* m_pGage;						// �Q�[�W

	Player* m_pPlayer;					// �v���C���[

public:
	CREATE_FUNC(PlayScene);
	virtual bool init();

	// �V�[�����쐬����
	static cocos2d::Scene* createScene();

	void update(float delta);				// �X�V����

	void FallFood();						// �H�ނ𗎂Ƃ�

	// �^�b�`�֌W�̊֐��錾
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);

	// �ÓI�����o
	static int m_time;						// ����
};