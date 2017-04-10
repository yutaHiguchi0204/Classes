//��----------------------------------------------------��
//��*�t�@�C�����FPlayer.cpp								��
//��*���e�@�@�@�F�v���C���[�N���X						��
//��*����ҁ@�@�FAyaka Yamanaka							��
//��*��������@�F2017.04.07								��
//��----------------------------------------------------��

#include "Player.h"

#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	setTexture("player_all.png");
	Rect rect = { 0, 0, 96, 96 };
	setTextureRect(rect);
	setPosition(Vec2(320, 480));
	put_cnt = 0;
	pos = getPosition();

	return true;
}

//�A�b�v�f�[�g
void Player::Update()
{
	pos = getPosition();
}

//����
//cnt��main����擾���āA�A�j���[�V����
//cnt��0�`3�A30�t���[����1�R�}
void Player::Put(int cnt)
{
	put_cnt = cnt;
	float grp_x;
	grp_x = put_cnt / 30;
	Rect rect = {grp_x * 96, 0, 96, 96};
	setTextureRect(rect);


	////�A�j���[�V����
	//switch (put_cnt / 30)
	//{
	//case 0:
	//	setTexture("player.png");
	//	break;
	//case 1:
	//	setTexture("player2.png");
	//	break;
	//case 2:
	//	setTexture("player3.png");
	//	break;
	//case 3:
	//	setTexture("player2.png");
	//	break;
	//case 4:
	//	setTexture("player.png");
	//	break;
	//}


	return;

}

//����(�^�b�`���ꂽ�ꏊ�Ɍ������āj
void Player::Move(Vec2 touch_pos)
{
	next_pos = touch_pos;
	MoveTo* move = MoveTo::create(1.0f, next_pos);
	move->setTag(1);
	runAction(move);
}

//�p�x�����߂�
float Player::Get_degree(cocos2d::Vec2 pos, cocos2d::Vec2 touch_pos)
{
	float radian;		
	//�p�x��radian�Ŏ擾
	radian = ccpToAngle(ccpSub(pos, touch_pos));
	//degree�ɕϊ�
	float degree = CC_RADIANS_TO_DEGREES(radian);
	degree *= -1;
	degree -= 90.0f;

	return degree;
}
