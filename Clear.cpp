//���e		Clear�N���X�̃\�[�X�t�@�C��
//����ҁ@	�o���ї�
//�����	2017/04/07

//�w�b�_�[�t�@�C���̃C���N���[�h
#include "Clear.h"
#include "audio\include\AudioEngine.h"
#include "TitleScene.h"

// ���O���
USING_NS_CC;

using namespace cocos2d::experimental;

//�V�[���Ǘ�
Scene* ClearScene::createScene()
{
	// �V�[�����쐬����
	auto scene = Scene::create();

	// ���C���[���쐬����
	auto layer = ClearScene::create();

	// ���C���[���V�[���ɒǉ�����
	scene->addChild(layer);

	// �V�[����Ԃ�
	return scene;
}

//�����ݒ�
bool ClearScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// �X�V��������
	scheduleUpdate();

	// �w�i
	m_back = Sprite::create("clear.png");
	//m_back = Sprite::create("over.png");
	m_back->setPosition(Vec2(480.0f, 320.0f));
	this->addChild(m_back);

	m_cnt = 0;
	m_time = 0;

	//BGM�Đ�
	clear_bgm = AudioEngine::play2d("clear.ogg");

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ClearScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

//�X�V����
void ClearScene::update(float delta)
{
	m_cnt++;
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

bool ClearScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = TitleScene::createScene();
	// ���̃V�[���Ɉڍs
	//BGM�~�߂�
	AudioEngine::stop(clear_bgm);

	_director->replaceScene(nextScene);

	return false;
}
