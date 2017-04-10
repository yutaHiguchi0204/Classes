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
	return true;
}

//�X�V����
void Food::update()
{

}

//�X�V����
void Food::texture(float dt, b2World* world, b2Body* Body)
{
	//�l�p�`�̌`��f�[�^�����
	b2PolygonShape dynamicBox;

	////1m�l���̐����`���w��i�����ő傫����ς���j
	dynamicBox.SetAsBox(1.0f, 1.0f);

	//���̂ɃX�v���C�g��\��(��)
	Sprite* spr = Sprite::create("suika.png");
	this->addChild(spr);

	//���[���h�ɐV���ȃ_�C�i�~�b�N�{�f�B��ǉ�����
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(800.0f / PTM_RATIO, 640.0f / PTM_RATIO);
	bodyDef.userData = spr;
	Body = world->CreateBody(&bodyDef);

	//�_�C�i�~�b�N�{�f�B�Ɏl�p�`�̃t�B�N�X�`����ǉ�����
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.restitution;
	Body->CreateFixture(&fixtureDef);
}