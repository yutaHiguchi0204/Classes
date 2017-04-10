/* =====================================================================
//! @param		�uPlayScene�v�N���X�̃\�[�X�t�@�C��
//! @create		����@�T��
//! @date		17/04/07
===================================================================== */

// �w�b�_�t�@�C���̃C���N���[�h
#include "PlayScene.h"
#include "Food.h"
#include "audio\include\AudioEngine.h"

//���s�N�Z����1���[�g����
#define PTM_RATIO 32
#define MAX_HEIGHT 20		//����
#define MAX_WIDTH 30		//��

// ���O���
USING_NS_CC;
using namespace cocos2d::experimental;

int PlayScene::m_time;

// �����o�֐��̒�`

// �V�[���Ǘ�
Scene* PlayScene::createScene()
{
	// �V�[�����쐬����
	auto scene = Scene::create();

	// ���C���[���쐬����
	auto layer = PlayScene::create();

	// ���C���[���V�[���ɒǉ�����
	scene->addChild(layer);

	// �V�[����Ԃ�
	return scene;
}

//�����V�X�e���̏�����
void PlayScene::initPhysics()
{
	//�������[���h�̏d�͂�ݒ�
	b2Vec2 gravity;

	//�������ɖ��t���[������
	gravity.Set(0.0f, -9.8f);

	//���[���h�̐���
	m_pWorld = new b2World(gravity);

	//�\���p�̃C���X�^���X�𐶐�
	m_pDraw = new GLESDebugDraw(PTM_RATIO);

	//�S��ޕ\���i�Sbit�}�X�N�j
	uint32 flags = 0xffffffff;
	m_pDraw->SetFlags(flags);

	//�\���p�C���X�^���X�����[���h�ɃZ�b�g
	m_pWorld->SetDebugDraw(m_pDraw);

	//�ǑS�̂�1�̃{�f�B�ɂ���
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);	//��ʍ������Z���^�[��
	b2Body* groundBody = m_pWorld->CreateBody(&groundBodyDef);

	//�ݑ܂̍��̂̈ʒu�̐ݒ�
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

	//�s�N�Z�������[�g���ɕϊ�����
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

	//�V�F�C�v�ݒ�p�̃C���X�^���X�i�g���܂킷�j
	b2EdgeShape groundBox;

	//�ݑ܂̍��̂̐ݒu
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

//�f�X�g���N�^
PlayScene::~PlayScene()
{
	//���
	delete m_pDraw;
	delete m_pWorld;
}

// �����ݒ�
bool PlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	

	//�^�C�}�[�̏�����
	m_timer = 0;

	//�����V�X�e���̏�����
	initPhysics();

	// �X�V��������
	scheduleUpdate();

	// �����o�ϐ��̏�����
	m_time = 0;

	// �w�i
	m_pBack = Sprite::create("back.png");
	m_pBack->setPosition(Vec2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));
	this->addChild(m_pBack);

	// �l��
	m_pHuman = Human::create();
	this->addChild(m_pHuman);

	// ��
	m_pStomach = Sprite::create("stomach.png");
	m_pStomach->setPosition(Vec2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));
	this->addChild(m_pStomach);

	// �Q�[�W
	m_pGage = Gage::create();
	m_pGage->setPosition(Vec2(WINDOW_WIDTH - 48.0f, 32.0f));
	this->addChild(m_pGage);

	// �Q�[�W�t���[����`��
	Sprite* gageFrame = Sprite::create("gageFrame.png");
	gageFrame->setAnchorPoint(Vec2(0, 0));
	gageFrame->setPosition(m_pGage->getPosition());
	this->addChild(gageFrame);

	//�H��
	food = Food::create();
	this->addChild(food);

	m_pGage->SetGage(1);

	// �v���C���[
	m_player = Player::create();
	this->addChild(m_player);

	//�A�j���[�V�����p�J�E���g������
	cnt = 0;
	//����ł��邩�ۂ��i�����l�j
	put = false;

	// �C�x���g���X�i�[�쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);

	// �C�x���g���X�i�[�o�^
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	int back_graund = AudioEngine::play2d("puzzle.ogg");
	//int heart = AudioEngine::play2d("heart1.ogg");
	AudioEngine::setLoop(back_graund, true);
	//AudioEngine::setLoop(heart, true);

	return true;
}

/* =====================================================================
//! ���@�e		�X�V����
//! ���@��		�_�~�[�����ifloat�j
//! �߂�l		�Ȃ�
===================================================================== */
void PlayScene::update(float delta)
{
	//// ���Ԍv��
	//m_time++;

	//�^�C�}�[��i�߂�
	m_timer++;

	//�������[���h�̍X�V�i���Ԃ�i�߂�j
	m_pWorld->Step(1.0f / 60.0f, 8, 3);

	//�������[���h���̑S�Ẵ{�f�B�ɂ��ď���
	for (m_pBody = m_pWorld->GetBodyList(); m_pBody != nullptr; m_pBody = m_pBody->GetNext())
	{
		//UserData�ɂ��܂��Ă�����Sprite���擾
		Sprite* sprite = (Sprite*)m_pBody->GetUserData();

		//���炩����Sprite�����܂��Ă���ꍇ�̂�
		if (sprite != nullptr)
		{
			//�������[���h���̍��̂̍��W���擾���āA�����ʒu��Sprite���ړ�
			b2Vec2 pos = m_pBody->GetPosition();
			sprite->setPosition(pos.x * PTM_RATIO, pos.y * PTM_RATIO);

			//�������[���h���̍��̂̊p�x���擾���āA�����p�x��Sprite����]
			float rot = m_pBody->GetAngle();
			sprite->setRotation(-CC_DEGREES_TO_RADIANS(rot));
		}
	}


	//2�b���ƂɐH�ނ��o������
	if (m_timer % 120 == 0)
	{
		food->texture(a, m_pWorld, m_pBody);
	}

	// �H�ނ𗎂Ƃ�
	if (m_time % INTERVAL_FOOD == 0)
	{
		FallFood();
	}

	m_player->Update();
	//����ł�����A�A�j���[�V����
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
//! ���@�e		�H�ނ𗎂Ƃ�
//! ���@��		�Ȃ�
//! �߂�l		�Ȃ�
===================================================================== */
void PlayScene::FallFood()
{
	
}

// �^�b�`�J�n���ɌĂ΂��֐�
bool PlayScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	//�^�b�`���W�擾
	Vec2 touch_pos = touch->getLocation();
	Rect rect_player = m_player->getBoundingBox();

	//�Q�񔻒肳��Ȃ��悤�ɂ��邽�߂̕ϐ�
	static int move = 0;

	//�����蔻��
	bool hit = rect_player.containsPoint(touch_pos);

	//�v���C���[���^�b�`���Ă�����
	if (hit)
	{
		//����
		put = true;
	}
	//�v���C���[����Ȃ��Ƃ�����^�b�`���Ă�����
	else
	{
		//�P��ڂ̔���Ȃ�
		if (move == 0)
		{
			//������
			m_player->Move(touch_pos);
			//��]������p�x�����߂�
			float rottation = m_player->Get_degree(m_player->getPosition(), touch_pos);
			//�v���C���[����]������
			m_player->setRotation(rottation);
			move++;
		}
		//�Q�d�ɏd�Ȃ��Ă��܂��Ă�����
		else
		{
			move = 0;
		}
	}

	return true;
}

//�\���֐����I�[�o�[���C�h
void PlayScene::draw(Renderer* renderer, const Mat4& transform, uint32_t flags)
{
	//�������[���h���f�o�b�O�\��
	m_pWorld->DrawDebugData();
}