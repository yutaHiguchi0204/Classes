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
	return true;
}

//更新処理
void Food::update()
{

}

//更新処理
void Food::texture(float dt, b2World* world, b2Body* Body)
{
	//四角形の形状データを作る
	b2PolygonShape dynamicBox;

	////1m四方の正方形を指定（ここで大きさを変える）
	dynamicBox.SetAsBox(1.0f, 1.0f);

	//剛体にスプライトを貼る(仮)
	Sprite* spr = Sprite::create("suika.png");
	this->addChild(spr);

	//ワールドに新たなダイナミックボディを追加する
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(800.0f / PTM_RATIO, 640.0f / PTM_RATIO);
	bodyDef.userData = spr;
	Body = world->CreateBody(&bodyDef);

	//ダイナミックボディに四角形のフィクスチャを追加する
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.restitution;
	Body->CreateFixture(&fixtureDef);
}