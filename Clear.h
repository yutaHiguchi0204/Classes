//���e		Clear�N���X�̃w�b�_�t�@�C��
//����ҁ@	�o���ї�
//�����	2017/04/07
#pragma once

//�w�b�_�[�t�@�C���̃C���N���[�h
#include "cocos2d.h"

									//�N���X�̒�`
class ClearScene : public cocos2d::Scene
{
private:
	//�w�i
	cocos2d::Sprite* m_back;
	//�~���b�̃J�E���g
	int m_cnt;
	//�b���̃J�E���g
	int m_time;

public:
	CREATE_FUNC(ClearScene);
	virtual bool init();

	// �V�[�����쐬����
	static cocos2d::Scene* createScene();

	// �X�V����
	void update(float delta);

	//�^�b�`����
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);

};