//��----------------------------------------------------��
//��*�t�@�C�����FPlayer.cpp								��
//��*���e�@�@�@�F�v���C���[�N���X						��
//��*����ҁ@�@�FAyaka Yamanaka							��
//��*��������@�F2017.04.07								��
//��----------------------------------------------------��

#include "Player.h"

#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "audio\include\AudioEngine.h"

#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::experimental;


//PlayScene�̕ϐ����g�p
bool PlayScene::put;

//������
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

	AudioEngine::preload("apple1.ogg");

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
void Player::Put()
{
	//int put_se = AudioEngine::play2d("apple1.ogg");
	//AudioEngine::setLoop(put_se, true);
	put_cnt++;

	float grp_x;
	grp_x = put_cnt / 10;
	Rect rect = {grp_x * 96, 0, 96, 96};
	setTextureRect(rect);
	if (put_cnt > 90)
	{
		put_cnt = 0;
		PlayScene::put = false;
		Rect rect = { 0, 0, 96, 96 };
		setTextureRect(rect);
		//AudioEngine::stop(put_se);
		AudioEngine::uncache("apple1.ogg");
	}
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
