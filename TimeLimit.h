/**********************************************************************
// @param	「TimeLimit」クラスのヘッダファイル
// @create	樋口裕太
// @date	17/01/19
**********************************************************************/
#pragma once

// ヘッダファイルのインクルード
#include "cocos2d.h"

// 定数
const int NUM_SECOND = 60;		// 一秒

// クラスの定義
class TimeLimit : public cocos2d::Layer
{
public:
	virtual bool init();
	
	CREATE_FUNC(TimeLimit);

	static void timeCountDown(int* frame, int* time);				// カウントダウン
	
	static void timeDraw(cocos2d::Sprite* timeSpr, int time);		// 時間の描画
};