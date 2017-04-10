//∞----------------------------------------------------∞
//∞*ファイル名：Player.cpp								∞
//∞*内容　　　：プレイヤークラス						∞
//∞*制作者　　：Ayaka Yamanaka							∞
//∞*制作日時　：2017.04.07								∞
//∞----------------------------------------------------∞

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

	setTexture("player.png");
	setPosition(Vec2(320, 480));
	put_cnt = 0;
	pos = getPosition();
	//spd = (0, 0);

	scheduleUpdate();

	return true;
}

//挟む
//cntをmainから取得して、アニメーション
//cntは０～３
void Player::Put(int cnt)
{
	put_cnt = cnt;

	//アニメーション
	switch (put_cnt)
	{
	case 0:
		setTexture("player.png");
		break;
	case 1:
		setTexture("player2.png");
		break;
	case 2:
		setTexture("player3.png");
		break;
	case 3:
		setTexture("player2.png");
		break;
	}

	return;

}

//動く(タッチされた場所に向かって）
void Player::Move(Vec2 touch_pos)
{
}
