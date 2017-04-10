/**********************************************************************
// @param	「TimeLimit」クラスのソースファイル
// @create	樋口裕太
// @date	17/01/19
**********************************************************************/

// ヘッダファイルのインクルード
#include "TimeLimit.h"

USING_NS_CC;

// メンバ関数の定義

// 初期設定
bool TimeLimit::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

// カウントダウン
void TimeLimit::timeCountDown(int* frame, int* time)
{
	(*frame)++;
	if (*frame >= NUM_SECOND)
	{
		(*time)--;
		(*frame) = 0;
	}
}

// 時間の描画
void TimeLimit::timeDraw(Sprite* timeSpr, int time)
{
	timeSpr->setTextureRect(Rect{ time * 128.0f, 0.0f, 128.0f, 128.0f });
}