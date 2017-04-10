//日付　04/09
//作者　井坂亘汰
//内容　物理ワールドの設定

#include "Food.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Box2D\Box2D.h"

//何ピクセルで1メートルか
#define PTM_RATIO 32
#define MAX_HEIGHT 20		//高さ
#define MAX_WIDTH 30		//幅

#define RAND_FLOAT(LO, HI) LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(HI - LO)))

#define FOOD_POINT 3 

USING_NS_CC;

using namespace cocostudio::timeline;

//物理システムの初期化
void Food::initPhysics()
{

}

//デストラクタ
Food::~Food()
{

}

// on "init" you need to initialize your instance
bool Food::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	m_foodPoint = FOOD_POINT;

	return true;
}

//更新処理
void Food::update()
{

}

//テクスチャの貼り付け
void Food::texture(float dt, b2World* world, b2Body* Body)
{
	//丸の形状データを作る
	b2CircleShape dynamicBall;
	dynamicBall.m_radius = 1.0f;

	//剛体にスプライトを貼る(仮)
	Sprite* spr = Sprite::create("suika.png");
	spr->setPosition(Vec2(-32.0f, -32.0f));
	this->addChild(spr);

	//x軸の座標を乱数で取得する
	float rand_x = RAND_FLOAT(800.0f, 736.0f);

	//ワールドに新たなダイナミックボディを追加する
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(rand_x / PTM_RATIO, 672.0f / PTM_RATIO);
	bodyDef.userData = spr;
	Body = world->CreateBody(&bodyDef);

	//ダイナミックボディに丸のフィクスチャを追加する
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBall;
	fixtureDef.density = 100.0f;
	fixtureDef.restitution = 0.6f;
	Body->CreateFixture(&fixtureDef);
}