//���e		Gameover�N���X�̃w�b�_�t�@�C��
//����ҁ@	�o���ї�
//�����	2017/04/07
#pragma once

//�w�b�_�[�t�@�C���̃C���N���[�h
#include "cocos2d.h"

									//�N���X�̒�`
class GameoverScene : public cocos2d::Scene
{
private:
	//�w�i
	cocos2d::Sprite* m_back;
	//�L�������f���q�f��
	cocos2d::Sprite* m_reverse;
	//�A�j���[�V�����p�̐�
	cocos2d::Sprite* m_star;
	//�~���b�̃J�E���g
	int m_cnt;
	//�b���̃J�E���g
	int m_time;
	//�A�j���[�V�����̃J�E���g
	int m_actCnt;
	//�A�j���[�V�����̏o���̐؂�ւ�
	bool m_actSter;

public:
	CREATE_FUNC(GameoverScene);
	virtual bool init();

	// �V�[�����쐬����
	static cocos2d::Scene* createScene();

	// �X�V����
	void update(float delta);
	
	//�^�b�`����
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);

};