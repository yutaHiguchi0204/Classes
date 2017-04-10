//∞----------------------------------------------------∞
//∞*ファイル名：Player.h								∞
//∞*内容　　　：プレイヤークラス						∞
//∞*制作者　　：Ayaka Yamanaka							∞
//∞*制作日時　：2017.04.07								∞
//∞----------------------------------------------------∞

#pragma once
#include "cocos2d.h"

//プレイヤークラスの定義
class Player : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Player);
	virtual bool init();

	void Update();		//アップデート
	void Put();			//挟む動作
	void Move(cocos2d::Vec2 touch_pos);		//動く動作
	float Get_degree(cocos2d::Vec2 pos, cocos2d::Vec2 touch_pos);


private:
	cocos2d::Sprite* sprite;		//プレイヤーのスクリプト
	cocos2d::Vec2 pos;
	cocos2d::Vec2 next_pos;
	int put_cnt;

};