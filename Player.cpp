//∞----------------------------------------------------∞
//∞*ファイル名：Player.cpp								∞
//∞*内容　　　：プレイヤークラス						∞
//∞*制作者　　：Ayaka Yamanaka							∞
//∞*制作日時　：2017.04.07								∞
//∞----------------------------------------------------∞

#include "Player.h"

#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "audio\include\AudioEngine.h"

#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::experimental;


//PlaySceneの変数を使用
bool PlayScene::put;

//初期化
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

//アップデート
void Player::Update()
{
	pos = getPosition();
}

//挟む
//cntをmainから取得して、アニメーション
//cntは0～3、30フレームで1コマ
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

//動く(タッチされた場所に向かって）
void Player::Move(Vec2 touch_pos)
{
	next_pos = touch_pos;
	MoveTo* move = MoveTo::create(1.0f, next_pos);
	move->setTag(1);
	runAction(move);
}

//角度を求める
float Player::Get_degree(cocos2d::Vec2 pos, cocos2d::Vec2 touch_pos)
{
	float radian;		
	//角度をradianで取得
	radian = ccpToAngle(ccpSub(pos, touch_pos));
	//degreeに変換
	float degree = CC_RADIANS_TO_DEGREES(radian);
	degree *= -1;
	degree -= 90.0f;

	return degree;
}
