//��----------------------------------------------------��
//��*�t�@�C�����FPlayer.h								��
//��*���e�@�@�@�F�v���C���[�N���X						��
//��*����ҁ@�@�FAyaka Yamanaka							��
//��*��������@�F2017.04.07								��
//��----------------------------------------------------��

#pragma once
#include "cocos2d.h"

//�v���C���[�N���X�̒�`
class Player : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Player);
	virtual bool init();

	//void update(float delta);		//�A�b�v�f�[�g
	void Put(int cnt);			//���ޓ���
	void Move(cocos2d::Vec2 touch_pos);		//��������

private:
	cocos2d::Sprite* sprite;		//�v���C���[�̃X�N���v�g
	cocos2d::Vec2 pos;
	cocos2d::Vec2 spd;
	int put_cnt;

};