//���e		Clear�N���X�̃\�[�X�t�@�C��
//����ҁ@	�o���ї�
//�����	2017/04/07

//�w�b�_�[�t�@�C���̃C���N���[�h
#include "Clear.h"

// ���O���
USING_NS_CC;

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
	m_back->setPosition(Vec2(480.0f, 320.0f));
	this->addChild(m_back);

	m_cnt = 0;
	m_time = 0;

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