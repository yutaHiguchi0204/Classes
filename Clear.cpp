//内容		Clearクラスのソースファイル
//制作者　	出口紗良
//制作日	2017/04/07

//ヘッダーファイルのインクルード
#include "Clear.h"
#include "audio\include\AudioEngine.h"
#include "TitleScene.h"

// 名前空間
USING_NS_CC;

using namespace cocos2d::experimental;

//シーン管理
Scene* ClearScene::createScene()
{
	// シーンを作成する
	auto scene = Scene::create();

	// レイヤーを作成する
	auto layer = ClearScene::create();

	// レイヤーをシーンに追加する
	scene->addChild(layer);

	// シーンを返す
	return scene;
}

//初期設定
bool ClearScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// 更新処理準備
	scheduleUpdate();

	// 背景
	m_back = Sprite::create("clear.png");
	//m_back = Sprite::create("over.png");
	m_back->setPosition(Vec2(480.0f, 320.0f));
	this->addChild(m_back);

	m_cnt = 0;
	m_time = 0;

	//BGM再生
	clear_bgm = AudioEngine::play2d("clear.ogg");

	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ClearScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

//更新処理
void ClearScene::update(float delta)
{
	m_cnt++;
	if (m_cnt > 60)
	{
		m_time++;
		m_cnt = 0;
	}

	if (m_time > 5)
	{
		//シーン遷移先は一時的にPlaySceneに

		// 次のシーンを作成する
		//Scene* nextScene = PlayScene::create();
		//次のシーンに移行
		//_director->replaceScene(nextScene);
	}
}

bool ClearScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	// 次のシーンを作成する
	Scene* nextScene = TitleScene::createScene();
	// 次のシーンに移行
	//BGM止める
	AudioEngine::stop(clear_bgm);

	_director->replaceScene(nextScene);

	return false;
}
