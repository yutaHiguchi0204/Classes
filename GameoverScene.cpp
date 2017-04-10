//内容		Gameoverクラスのソースファイル
//制作者　	出口紗良
//制作日	2017/04/07

//ヘッダーファイルのインクルード
#include "GameoverScene.h"
#include "audio\include\AudioEngine.h"
#include "TitleScene.h"


// 名前空間
USING_NS_CC;
using namespace cocos2d::experimental;

//シーン管理
Scene* GameoverScene::createScene()
{
	// シーンを作成する
	auto scene = Scene::create();

	// レイヤーを作成する
	auto layer = GameoverScene::create();

	// レイヤーをシーンに追加する
	scene->addChild(layer);

	// シーンを返す
	return scene;
}

//初期設定
bool GameoverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// 更新処理準備
	scheduleUpdate();

	// 背景
	m_back = Sprite::create("over.png");
	m_back->setPosition(Vec2(480.0f, 320.0f));
	this->addChild(m_back);

	//アニメーションの作成
	m_reverse = Sprite::create("G1.png");
	m_reverse->setPosition(Vec2(520.0f, 50.0f));
	this->addChild(m_reverse);

	m_cnt = 0;
	m_time = 0;
	m_actCnt = 0;
	m_actSter = true;


	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameoverScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	//BGM再生
	over_bgm = AudioEngine::play2d("over.ogg");


	return true;
}

//更新処理
void GameoverScene::update(float delta)
{
	m_cnt++;
	m_actCnt++;

	//アニメーションの処理
	if (m_actCnt > 5)
	{
		MoveBy* act1 = MoveBy::create(1.0f, Vec2(-80.0f, -130.f));
		RemoveSelf* act2 = RemoveSelf::create(true);
		Sequence* ACT = Sequence::create(act1, act2, nullptr);
		m_star = Sprite::create("star.png");
		if (m_actSter == true)
		{
			m_star->setPosition(Vec2(600.0f, 140.0f));
			m_actSter = false;
		}
		else if (m_actSter == false)
		{
			m_star->setPosition(Vec2(560.0f, 140.0f));
			m_actSter = true;
		}
		this->addChild(m_star);
		m_star->runAction(ACT);

		m_actCnt = 0;
	}

	//時間でシーン遷移（５秒）
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

bool GameoverScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	// 次のシーンを作成する
	Scene* nextScene = TitleScene::createScene();
	// 次のシーンに移行
	//BGM止める
	AudioEngine::stop(over_bgm);
	_director->replaceScene(nextScene);


	return false;
}
