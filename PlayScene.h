/* =====================================================================
//! @param		「PlayScene」クラスのヘッダファイル
//! @create		樋口　裕太
//! @date		17/04/07
===================================================================== */
#pragma once

// ヘッダファイルのインクルード
#include "cocos2d.h"
#include "Gage.h"
#include "Food.h"
#include "Human.h"
#include "Player.h"

//box2dを使うために必要
#include "Box2D\Box2D.h" 
#include "GLES-Render.h"

// 定数
const int WINDOW_WIDTH = 960;						// 画面の幅
const int WINDOW_HEIGHT = 640;						// 画面の高さ
const int NUM_TIME = 60;							// １回のゲーム時間
const int INTERVAL_FOOD = 60 * 2;					// 食材が落ちてくる間隔

// クラスの定義
class PlayScene : public cocos2d::Scene
{
private:
	cocos2d::Sprite* m_pBack;			// 背景
	cocos2d::Sprite* m_pStomach;		// 胃

	cocos2d::Sprite* m_pTimeOneFloor;	// 一の位
	cocos2d::Sprite* m_pTimeTenFloor;	// 十の位
	int m_countDown;					// カウントダウン

	Gage* m_pGage;						//ゲージ
	Food* food;							//食料
	Human* m_pHuman;					// 人間
	Player* m_pPlayer;					// プレイヤー

	b2World* m_pWorld;				//物理ワールド
	b2Body* m_pBody;
	GLESDebugDraw* m_pDraw;			//表示用インスタンス

	float a;						//ダミー引数

	int back_graund;				//BGMのタグ
	int heart;						//心臓音のタグ

public:
	CREATE_FUNC(PlayScene);

	//物理システムの初期化
	void initPhysics();

	//表示関数をオーバーライド
	void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);

	//初期化
	virtual bool init();

	//デストラクタ
	~PlayScene();

	// シーンを作成する
	static cocos2d::Scene* createScene();
	
	//更新処理
	void update(float delta);

	// 食材を落とす
	void FallFood();

	// タッチ関係の関数宣言
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);

	bool isCollision(cocos2d::Vec2 playerVec, cocos2d::Vec2 foodVec)
	{
		if ((playerVec.x <= foodVec.x + 32) &&
			(playerVec.x + 96 >= foodVec.x))
		{
			if ((playerVec.y <= foodVec.y + 32) &&
				(playerVec.y + 96 >= foodVec.y))
			{
				return true;
			}
		}

		return false;
	}

	// シーン移動
	void GameoverTransScene();				// ゲームオーバーシーンに移動
	void ClearTransScene();					// クリアシーンに移動

	// 静的メンバ
	static int m_time;						// 時間
	static bool put;
};