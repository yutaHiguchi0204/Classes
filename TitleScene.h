/* =====================================================================
//! @param		�uTitleScene�v�N���X�̃w�b�_�t�@�C��
//! @create		����@�T��
//! @date		17/04/10
===================================================================== */
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include "cocos2d.h"

// �N���X�̒�`
class TitleScene : public cocos2d::Scene
{
private:
	cocos2d::Sprite* m_pTitleBack;			// �^�C�g���摜
	cocos2d::Sprite* m_pTitleMsg;			// �^�b�v���Ă˃��b�Z�[�W

	float moveX;							// �����p�x
	
	int title_bgm;							//BGM�̃^�O

public:
	CREATE_FUNC(TitleScene);
	virtual bool init();

	// �V�[�����쐬����
	static cocos2d::Scene* createScene();

	// �X�V����
	void update(float delta);

	// �^�b�`�֌W�̊֐��錾
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);
};