/* =====================================================================
//! @param		「Gage」クラスのソースファイル
//! @create		樋口　裕太
//! @date		17/04/07
===================================================================== */

// ヘッダファイルのインクルード
#include "Gage.h"
#include "Human.h"

// 名前空間
USING_NS_CC;

// メンバ関数の定義

// 初期設定
bool Gage::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	setTexture("gage.png");
	setAnchorPoint(Vec2(0, 0));
	setScaleY(0);

	return true;
}

/* =====================================================================
//! 内　容		ゲージ設定
//! 引　数		満腹度（int）
//! 戻り値		なし
===================================================================== */
void Gage::SetGage(int fullPoint)
{
	setScaleY(static_cast<float>(fullPoint) / MAX_FULLPOINT);
}