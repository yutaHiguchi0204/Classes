/* =====================================================================
//! @param		「Gage」クラスのヘッダファイル
//! @create		樋口　裕太
//! @date		17/04/07
===================================================================== */
#pragma once

// ヘッダファイルのインクルード
#include "cocos2d.h"

// クラスの定義
class Gage : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Gage);
	virtual bool init();

	void SetGage(int fullPoint);		// ゲージのセット
};