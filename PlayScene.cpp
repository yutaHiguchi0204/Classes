/* =====================================================================
//! @param		�uPlayScene�v�N���X�̃\�[�X�t�@�C��
//! @create		����@�T��
//! @date		17/04/07
===================================================================== */

// �w�b�_�t�@�C���̃C���N���[�h
#include "PlayScene.h"
#include "Food.h"

// ���O���
USING_NS_CC;

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

// �����ݒ�
bool PlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

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

	// �v���C���[
	m_pPlayer = Player::create();
	this->addChild(m_pPlayer);

	// �C�x���g���X�i�[�쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);

	// �C�x���g���X�i�[�o�^
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

/* =====================================================================
//! ���@�e		�X�V����
//! ���@��		�_�~�[�����ifloat�j
//! �߂�l		�Ȃ�
===================================================================== */
void PlayScene::update(float delta)
{
	// ���Ԍv��
	m_time++;

	// �H�ނ𗎂Ƃ�
	if (m_time % INTERVAL_FOOD == 0)
	{
		FallFood();
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