/* =====================================================================
//! @param		「Human」クラスのヘッダファイル
//! @create		樋口　裕太
//! @date		17/04/07
===================================================================== */
#pragma once

// ヘッダファイルのインクルード
#include "cocos2d.h"

// 定数
const int MAX_FULLPOINT = 100;			// 最大満腹度

// クラスの定義
class Human : public cocos2d::Layer
{
private:
	int m_fullPoint;					// お腹の貯まり具合

public:
	CREATE_FUNC(Human);
	virtual bool init();

	void SetFullPoint(int point);		// 満腹度を設定
	int GetFullPoint();					// 満腹度を取得
};