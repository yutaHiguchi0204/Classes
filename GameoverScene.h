//内容		Gameoverクラスのヘッダファイル
//制作者　	出口紗良
//制作日	2017/04/07
#pragma once

//ヘッダーファイルのインクルード
#include "cocos2d.h"

									//クラスの定義
class GameoverScene : public cocos2d::Scene
{
private:
	//背景
	cocos2d::Sprite* m_back;
	//キャラが吐く嘔吐物
	cocos2d::Sprite* m_reverse;
	//アニメーション用の星
	cocos2d::Sprite* m_star;
	//ミリ秒のカウント
	int m_cnt;
	//秒数のカウント
	int m_time;
	//アニメーションのカウント
	int m_actCnt;
	//アニメーションの出方の切り替え
	bool m_actSter;

public:
	CREATE_FUNC(GameoverScene);
	virtual bool init();

	// シーンを作成する
	static cocos2d::Scene* createScene();

	// 更新処理
	void update(float delta);
	
	//タッチ操作
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);

};