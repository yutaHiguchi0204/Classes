//���t�@04/09
//��ҁ@���j��
//���e�@�H�ނ̐ݒ�

#pragma once
#include "cocos2d.h"

//box2d���g�����߂ɕK�v
#include "Box2D\Box2D.h" 
#include "GLES-Render.h"

class Food : public cocos2d::Layer
{
private:

public:
	CREATE_FUNC(Food);

	//�X�V����
	void update();

	//���̂̐���
	void texture(float dt, b2World* World, b2Body* Body);

	//�����V�X�e���̏�����
	void initPhysics();

	//������
	virtual bool init();

	//�f�X�g���N�^
	~Food();
};