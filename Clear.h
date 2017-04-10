//内容		Clearクラスのヘッダファイル
//制作者　	出口紗良
//制作日	2017/04/07
#pragma once

//ヘッダーファイルのインクルード
#include "cocos2d.h"

									//クラスの定義
class ClearScene : public cocos2d::Scene
{
private:
	//背景
	cocos2d::Sprite* m_back;
	//ミリ秒のカウント
	int m_cnt;
	//秒数のカウント
	int m_time;

public:
	CREATE_FUNC(ClearScene);
	virtual bool init();

	// シーンを作成する
	static cocos2d::Scene* createScene();

	// 更新処理
	void update(float delta);

	//タッチ操作
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);

};