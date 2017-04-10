/* =====================================================================
//! @param		「PlayScene」クラスのソースファイル
//! @create		樋口　裕太
//! @date		17/04/07
===================================================================== */

// ヘッダファイルのインクルード
#include "PlayScene.h"
#include "Food.h"

// 名前空間
USING_NS_CC;

int PlayScene::m_time;

// メンバ関数の定義

// シーン管理
Scene* PlayScene::createScene()
{
	// シーンを作成する
	auto scene = Scene::create();

	// レイヤーを作成する
	auto layer = PlayScene::create();

	// レイヤーをシーンに追加する
	scene->addChild(layer);

	// シーンを返す
	return scene;
}

// 初期設定
bool PlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// 更新処理準備
	scheduleUpdate();

	// メンバ変数の初期化
	m_time = 0;

	// 背景
	m_pBack = Sprite::create("back.png");
	m_pBack->setPosition(Vec2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));
	this->addChild(m_pBack);

	// 人間
	m_pHuman = Human::create();
	this->addChild(m_pHuman);

	// 胃
	m_pStomach = Sprite::create("stomach.png");
	m_pStomach->setPosition(Vec2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));
	this->addChild(m_pStomach);

	// ゲージ
	m_pGage = Gage::create();
	m_pGage->setPosition(Vec2(WINDOW_WIDTH - 48.0f, 32.0f));
	this->addChild(m_pGage);

	// ゲージフレームを描画
	Sprite* gageFrame = Sprite::create("gageFrame.png");
	gageFrame->setAnchorPoint(Vec2(0, 0));
	gageFrame->setPosition(m_pGage->getPosition());
	this->addChild(gageFrame);

	// プレイヤー
	m_pPlayer = Player::create();
	this->addChild(m_pPlayer);

	// イベントリスナー作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// イベントリスナーに各コールバック関数をセットする
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);

	// イベントリスナー登録
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

/* =====================================================================
//! 内　容		更新処理
//! 引　数		ダミー引数（float）
//! 戻り値		なし
===================================================================== */
void PlayScene::update(float delta)
{
	// 時間計測
	m_time++;

	// 食材を落とす
	if (m_time % INTERVAL_FOOD == 0)
	{
		FallFood();
	}
}

/* =====================================================================
//! 内　容		食材を落とす
//! 引　数		なし
//! 戻り値		なし
===================================================================== */
void PlayScene::FallFood()
{
	
}

// タッチ開始時に呼ばれる関数
bool PlayScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	Vec2 touchPos = touch->getLocation();

	Rect rectPlayer = m_pPlayer->getBoundingBox();

	if (rectPlayer.containsPoint(touchPos))
	{
		
	}
	else
	{
		m_pPlayer->Move(touchPos);
	}

	return false;
}