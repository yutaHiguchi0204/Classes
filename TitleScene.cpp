/* =====================================================================
//! @param		「TitleScene」クラスのソースファイル
//! @create		樋口　裕太
//! @date		17/04/10
===================================================================== */

// ヘッダファイルのインクルード
#include "TitleScene.h"
#include "PlayScene.h"
#include "audio\include\AudioEngine.h"

// 名前空間
USING_NS_CC;
using namespace cocos2d::experimental;

// 定数
const float SPEED_MESSAGE_MOVE = 5.0f;				// メッセージの動く速度

// メンバ関数の定義

// シーン管理
Scene* TitleScene::createScene()
{
	// シーンを作成する
	auto scene = Scene::create();

	// レイヤーを作成する
	auto layer = TitleScene::create();

	// レイヤーをシーンに追加する
	scene->addChild(layer);

	// シーンを返す
	return scene;
}

// 初期設定
bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// 更新処理準備
	scheduleUpdate();

	// タイトル
	m_pTitleBack = Sprite::create("titleBack.png");
	m_pTitleBack->setPosition(Vec2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));
	this->addChild(m_pTitleBack);

	// メッセージ
	m_pTitleMsg = Sprite::create("titleMsg.png");
	m_pTitleMsg->setPosition(Vec2(WINDOW_WIDTH / 2.0f, 128.0f));
	this->addChild(m_pTitleMsg);

	// メッセージを横に動かす
	moveX = SPEED_MESSAGE_MOVE;

	// イベントリスナー作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// イベントリスナーに各コールバック関数をセットする
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);

	// イベントリスナー登録
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	title_bgm = AudioEngine::play2d("title.ogg");
	AudioEngine::setLoop(title_bgm, true);


	return true;
}

/* =====================================================================
//! 内　容		更新処理
//! 引　数		ダミー引数（float）
//! 戻り値		なし
===================================================================== */
void TitleScene::update(float delta)
{
	// メッセージの移動
	m_pTitleMsg->setPositionX(m_pTitleMsg->getPositionX() + moveX);

	// メッセージの当たり判定
	if (m_pTitleMsg->getPositionX() < 0 + 288.0f || m_pTitleMsg->getPositionX() > WINDOW_WIDTH - 288.0f)
	{
		moveX *= -1;
	}
}

// タッチ開始時に呼ばれる関数
bool TitleScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	// 次のシーンを作成する
	Scene* nextScene = PlayScene::create();

	//BGM止める
	AudioEngine::stop(title_bgm);
	//ボタン音流す
	int buttun = AudioEngine::play2d("touch.ogg");
	// 次のシーンに移行
	_director->replaceScene(nextScene);

	return true;
}