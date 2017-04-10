/* =====================================================================
//! @param		「PlayScene」クラスのヘッダファイル
//! @create		樋口　裕太
//! @date		17/04/07
===================================================================== */
#pragma once

// ヘッダファイルのインクルード
#include "cocos2d.h"
#include "Gage.h"
#include "Human.h"
#include "Player.h"

// 定数
const int WINDOW_WIDTH = 960;						// 画面の幅
const int WINDOW_HEIGHT = 640;						// 画面の高さ
const int NUM_SECOND = 60;							// １秒
const int INTERVAL_FOOD = NUM_SECOND * 2;			// 食材が落ちてくる間隔

// クラスの定義
class PlayScene : public cocos2d::Scene
{
private:
	cocos2d::Sprite* m_pBack;			// 背景
	cocos2d::Sprite* m_pStomach;		// 胃

	Human* m_pHuman;					// 人間

	Gage* m_pGage;						// ゲージ

	Player* m_pPlayer;					// プレイヤー

public:
	CREATE_FUNC(PlayScene);
	virtual bool init();

	// シーンを作成する
	static cocos2d::Scene* createScene();

	void update(float delta);				// 更新処理

	void FallFood();						// 食材を落とす

	// タッチ関係の関数宣言
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);

	// 静的メンバ
	static int m_time;						// 時間
};