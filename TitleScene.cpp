/* =====================================================================
//! @param		�uTitleScene�v�N���X�̃\�[�X�t�@�C��
//! @create		����@�T��
//! @date		17/04/10
===================================================================== */

// �w�b�_�t�@�C���̃C���N���[�h
#include "TitleScene.h"
#include "PlayScene.h"
#include "audio\include\AudioEngine.h"

// ���O���
USING_NS_CC;
using namespace cocos2d::experimental;

// �萔
const float SPEED_MESSAGE_MOVE = 5.0f;				// ���b�Z�[�W�̓������x

// �����o�֐��̒�`

// �V�[���Ǘ�
Scene* TitleScene::createScene()
{
	// �V�[�����쐬����
	auto scene = Scene::create();

	// ���C���[���쐬����
	auto layer = TitleScene::create();

	// ���C���[���V�[���ɒǉ�����
	scene->addChild(layer);

	// �V�[����Ԃ�
	return scene;
}

// �����ݒ�
bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// �X�V��������
	scheduleUpdate();

	// �^�C�g��
	m_pTitleBack = Sprite::create("titleBack.png");
	m_pTitleBack->setPosition(Vec2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));
	this->addChild(m_pTitleBack);

	// ���b�Z�[�W
	m_pTitleMsg = Sprite::create("titleMsg.png");
	m_pTitleMsg->setPosition(Vec2(WINDOW_WIDTH / 2.0f, 128.0f));
	this->addChild(m_pTitleMsg);

	// ���b�Z�[�W�����ɓ�����
	moveX = SPEED_MESSAGE_MOVE;

	// �C�x���g���X�i�[�쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);

	// �C�x���g���X�i�[�o�^
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	title_bgm = AudioEngine::play2d("title.ogg");
	AudioEngine::setLoop(title_bgm, true);


	return true;
}

/* =====================================================================
//! ���@�e		�X�V����
//! ���@��		�_�~�[�����ifloat�j
//! �߂�l		�Ȃ�
===================================================================== */
void TitleScene::update(float delta)
{
	// ���b�Z�[�W�̈ړ�
	m_pTitleMsg->setPositionX(m_pTitleMsg->getPositionX() + moveX);

	// ���b�Z�[�W�̓����蔻��
	if (m_pTitleMsg->getPositionX() < 0 + 288.0f || m_pTitleMsg->getPositionX() > WINDOW_WIDTH - 288.0f)
	{
		moveX *= -1;
	}
}

// �^�b�`�J�n���ɌĂ΂��֐�
bool TitleScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = PlayScene::create();

	//BGM�~�߂�
	AudioEngine::stop(title_bgm);
	//�{�^��������
	int buttun = AudioEngine::play2d("touch.ogg");
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return true;
}