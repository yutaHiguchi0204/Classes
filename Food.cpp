//���t�@04/09
//��ҁ@���j��
//���e�@�������[���h�̐ݒ�

#include "Food.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Box2D\Box2D.h"

//���s�N�Z����1���[�g����
#define PTM_RATIO 32
#define MAX_HEIGHT 20		//����
#define MAX_WIDTH 30		//��

#define RAND_FLOAT(LO, HI) LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(HI - LO)))

#define FOOD_POINT 3 

USING_NS_CC;

using namespace cocostudio::timeline;

//�����V�X�e���̏�����
void Food::initPhysics()
{

}

//�f�X�g���N�^
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

//�X�V����
void Food::update()
{

}

//�e�N�X�`���̓\��t��
void Food::texture(float dt, b2World* world, b2Body* Body)
{
	//�ۂ̌`��f�[�^�����
	b2CircleShape dynamicBall;
	dynamicBall.m_radius = 1.0f;

	//���̂ɃX�v���C�g��\��(��)
	Sprite* spr = Sprite::create("suika.png");
	spr->setPosition(Vec2(-32.0f, -32.0f));
	this->addChild(spr);

	//x���̍��W�𗐐��Ŏ擾����
	float rand_x = RAND_FLOAT(800.0f, 736.0f);

	//���[���h�ɐV���ȃ_�C�i�~�b�N�{�f�B��ǉ�����
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(rand_x / PTM_RATIO, 672.0f / PTM_RATIO);
	bodyDef.userData = spr;
	Body = world->CreateBody(&bodyDef);

	//�_�C�i�~�b�N�{�f�B�Ɋۂ̃t�B�N�X�`����ǉ�����
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBall;
	fixtureDef.density = 100.0f;
	fixtureDef.restitution = 0.6f;
	Body->CreateFixture(&fixtureDef);
}