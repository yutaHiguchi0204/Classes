/* =====================================================================
//! @param		「TitleScene」クラスのヘッダファイル
//! @create		樋口　裕太
//! @date		17/04/10
===================================================================== */
#pragma once

// ヘッダファイルのインクルード
#include "cocos2d.h"

// クラスの定義
class TitleScene : public cocos2d::Scene
{
private:
	cocos2d::Sprite* m_pTitleBack;			// タイトル画像
	cocos2d::Sprite* m_pTitleMsg;			// タップしてねメッセージ

	float moveX;							// 初期角度
	
	int title_bgm;							//BGMのタグ

public:
	CREATE_FUNC(TitleScene);
	virtual bool init();

	// シーンを作成する
	static cocos2d::Scene* createScene();

	// 更新処理
	void update(float delta);

	// タッチ関係の関数宣言
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);
};