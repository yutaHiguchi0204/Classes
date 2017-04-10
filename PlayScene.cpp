/* =====================================================================
//! @param		「PlayScene」クラスのソースファイル
//! @create		樋口　裕太
//! @date		17/04/07
===================================================================== */

// ヘッダファイルのインクルード
#include "PlayScene.h"
#include "Food.h"
#include "audio\include\AudioEngine.h"

//何ピクセルで1メートルか
#define PTM_RATIO 32
#define MAX_HEIGHT 20		//高さ
#define MAX_WIDTH 30		//幅

// 名前空間
USING_NS_CC;
using namespace cocos2d::experimental;

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

//物理システムの初期化
void PlayScene::initPhysics()
{
	//物理ワールドの重力を設定
	b2Vec2 gravity;

	//下方向に毎フレーム加速
	gravity.Set(0.0f, -9.8f);

	//ワールドの生成
	m_pWorld = new b2World(gravity);

	//表示用のインスタンスを生成
	m_pDraw = new GLESDebugDraw(PTM_RATIO);

	//全種類表示（全bitマスク）
	uint32 flags = 0xffffffff;
	m_pDraw->SetFlags(flags);

	//表示用インスタンスをワールドにセット
	m_pWorld->SetDebugDraw(m_pDraw);

	//壁全体で1つのボディにする
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);	//画面左下をセンターに
	b2Body* groundBody = m_pWorld->CreateBody(&groundBodyDef);

	//胃袋の剛体の位置の設定
	b2Vec2 one(80.0f, 0.0f);
	b2Vec2 two(80.0f, 32.0f);
	b2Vec2 three(32.0f, 32.0f);
	b2Vec2 four(32.0f, 608.0f);
	b2Vec2 five(752.0f, 608.0f);
	b2Vec2 six(752.0f, 640.0f);

	b2Vec2 seven(176.0f, 0.0f);
	b2Vec2 eight(176.0f, 32.0f);
	b2Vec2 nine(896.0f, 32.0f);
	b2Vec2 ten(896.0f, 608.0f);
	b2Vec2 eleven(848.0f, 608.0f);
	b2Vec2 twelve(848.0f, 640.0f);

	b2Vec2 thirteen(176.0f, 64.0f);
	b2Vec2 fourteen(208.0f, 64.0f);
	b2Vec2 fifteen(208.0f, 32.0f);

	//ピクセル→メートルに変換する
	one.x /= PTM_RATIO;
	one.y /= PTM_RATIO;
	two.x /= PTM_RATIO;
	two.y /= PTM_RATIO;
	three.x /= PTM_RATIO;
	three.y /= PTM_RATIO;
	four.x /= PTM_RATIO;
	four.y /= PTM_RATIO;
	five.x /= PTM_RATIO;
	five.y /= PTM_RATIO;
	six.x /= PTM_RATIO;
	six.y /= PTM_RATIO;
	seven.x /= PTM_RATIO;
	seven.y /= PTM_RATIO;
	eight.x /= PTM_RATIO;
	eight.y /= PTM_RATIO;
	nine.x /= PTM_RATIO;
	nine.y /= PTM_RATIO;
	ten.x /= PTM_RATIO;
	ten.y /= PTM_RATIO;
	eleven.x /= PTM_RATIO;
	eleven.y /= PTM_RATIO;
	twelve.x /= PTM_RATIO;
	twelve.y /= PTM_RATIO;
	thirteen.x /= PTM_RATIO;
	thirteen.y /= PTM_RATIO;
	fourteen.x /= PTM_RATIO;
	fourteen.y /= PTM_RATIO;
	fifteen.x /= PTM_RATIO;
	fifteen.y /= PTM_RATIO;

	//シェイプ設定用のインスタンス（使いまわす）
	b2EdgeShape groundBox;

	//胃袋の剛体の設置
	groundBox.Set(one, two);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(two, three);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(three, four);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(four, five);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(five, six);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(seven, eight);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(eight, nine);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(nine, ten);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(ten, eleven);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(eleven, twelve);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(eight, thirteen);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(thirteen, fourteen);
	groundBody->CreateFixture(&groundBox, 0);

	groundBox.Set(fourteen, fifteen);
	groundBody->CreateFixture(&groundBox, 0);
}

//デストラクタ
PlayScene::~PlayScene()
{
	//解放
	delete m_pDraw;
	delete m_pWorld;
}

// 初期設定
bool PlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	

	//タイマーの初期化
	m_timer = 0;

	//物理システムの初期化
	initPhysics();

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

	//食料
	food = Food::create();
	this->addChild(food);

	m_pGage->SetGage(1);

	// プレイヤー
	m_player = Player::create();
	this->addChild(m_player);

	//アニメーション用カウント初期化
	cnt = 0;
	//挟んでいるか否か（初期値）
	put = false;

	// イベントリスナー作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// イベントリスナーに各コールバック関数をセットする
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);

	// イベントリスナー登録
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	int back_graund = AudioEngine::play2d("puzzle.ogg");
	//int heart = AudioEngine::play2d("heart1.ogg");
	AudioEngine::setLoop(back_graund, true);
	//AudioEngine::setLoop(heart, true);

	return true;
}

/* =====================================================================
//! 内　容		更新処理
//! 引　数		ダミー引数（float）
//! 戻り値		なし
===================================================================== */
void PlayScene::update(float delta)
{
	//// 時間計測
	//m_time++;

	//タイマーを進める
	m_timer++;

	//物理ワールドの更新（時間を進める）
	m_pWorld->Step(1.0f / 60.0f, 8, 3);

	//物理ワールド内の全てのボディについて処理
	for (m_pBody = m_pWorld->GetBodyList(); m_pBody != nullptr; m_pBody = m_pBody->GetNext())
	{
		//UserDataにしまっておいたSpriteを取得
		Sprite* sprite = (Sprite*)m_pBody->GetUserData();

		//あらかじめSpriteがしまってある場合のみ
		if (sprite != nullptr)
		{
			//物理ワールド中の剛体の座標を取得して、同じ位置にSpriteを移動
			b2Vec2 pos = m_pBody->GetPosition();
			sprite->setPosition(pos.x * PTM_RATIO, pos.y * PTM_RATIO);

			//物理ワールド中の剛体の角度を取得して、同じ角度にSpriteを回転
			float rot = m_pBody->GetAngle();
			sprite->setRotation(-CC_DEGREES_TO_RADIANS(rot));
		}
	}


	//2秒ごとに食材が出現する
	if (m_timer % 120 == 0)
	{
		food->texture(a, m_pWorld, m_pBody);
	}

	// 食材を落とす
	if (m_time % INTERVAL_FOOD == 0)
	{
		FallFood();
	}

	m_player->Update();
	//挟んでいたら、アニメーション
	if (put)
	{
		m_player->Put(cnt);
		cnt++;
		if (cnt > 270)
		{
			cnt = 0;
			put = false;
			Rect rect = { 0, 0, 96, 96 };
			m_player->setTextureRect(rect);
		}

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
	//タッチ座標取得
	Vec2 touch_pos = touch->getLocation();
	Rect rect_player = m_player->getBoundingBox();

	//２回判定されないようにするための変数
	static int move = 0;

	//当たり判定
	bool hit = rect_player.containsPoint(touch_pos);

	//プレイヤーをタッチしていたら
	if (hit)
	{
		//挟む
		put = true;
	}
	//プレイヤーじゃないところをタッチしていたら
	else
	{
		//１回目の判定なら
		if (move == 0)
		{
			//動かす
			m_player->Move(touch_pos);
			//回転させる角度を求める
			float rottation = m_player->Get_degree(m_player->getPosition(), touch_pos);
			//プレイヤーを回転させる
			m_player->setRotation(rottation);
			move++;
		}
		//２重に重なってしまっていたら
		else
		{
			move = 0;
		}
	}

	return true;
}

//表示関数をオーバーライド
void PlayScene::draw(Renderer* renderer, const Mat4& transform, uint32_t flags)
{
	//物理ワールドをデバッグ表示
	m_pWorld->DrawDebugData();
}