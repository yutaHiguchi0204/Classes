//���e		Gameover�N���X�̃\�[�X�t�@�C��
//����ҁ@	�o���ї�
//�����	2017/04/07

//�w�b�_�[�t�@�C���̃C���N���[�h
#include "GameoverScene.h"
#include "audio\include\AudioEngine.h"
#include "TitleScene.h"


// ���O���
USING_NS_CC;
using namespace cocos2d::experimental;

//�V�[���Ǘ�
Scene* GameoverScene::createScene()
{
	// �V�[�����쐬����
	auto scene = Scene::create();

	// ���C���[���쐬����
	auto layer = GameoverScene::create();

	// ���C���[���V�[���ɒǉ�����
	scene->addChild(layer);

	// �V�[����Ԃ�
	return scene;
}

//�����ݒ�
bool GameoverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// �X�V��������
	scheduleUpdate();

	// �w�i
	m_back = Sprite::create("over.png");
	m_back->setPosition(Vec2(480.0f, 320.0f));
	this->addChild(m_back);

	//�A�j���[�V�����̍쐬
	m_reverse = Sprite::create("G1.png");
	m_reverse->setPosition(Vec2(520.0f, 50.0f));
	this->addChild(m_reverse);

	m_cnt = 0;
	m_time = 0;
	m_actCnt = 0;
	m_actSter = true;


	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameoverScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	//BGM�Đ�
	over_bgm = AudioEngine::play2d("over.ogg");


	return true;
}

//�X�V����
void GameoverScene::update(float delta)
{
	m_cnt++;
	m_actCnt++;

	//�A�j���[�V�����̏���
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

	//���ԂŃV�[���J�ځi�T�b�j
	if (m_cnt > 60)
	{
		m_time++;
		m_cnt = 0;
	}

	if (m_time > 5)
	{
		//�V�[���J�ڐ�͈ꎞ�I��PlayScene��

		// ���̃V�[�����쐬����
		//Scene* nextScene = PlayScene::create();
		//���̃V�[���Ɉڍs
		//_director->replaceScene(nextScene);
	}
}

bool GameoverScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = TitleScene::createScene();
	// ���̃V�[���Ɉڍs
	//BGM�~�߂�
	AudioEngine::stop(over_bgm);
	_director->replaceScene(nextScene);


	return false;
}
