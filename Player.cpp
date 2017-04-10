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

	setTexture("player_all.png");
	Rect rect = { 0, 0, 96, 96 };
	setTextureRect(rect);
	setPosition(Vec2(320, 480));
	put_cnt = 0;
	pos = getPosition();

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
void Player::Put(int cnt)
{
	put_cnt = cnt;
	float grp_x;
	grp_x = put_cnt / 30;
	Rect rect = {grp_x * 96, 0, 96, 96};
	setTextureRect(rect);


	////アニメーション
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
