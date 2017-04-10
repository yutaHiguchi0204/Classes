/* =====================================================================
//! @param		�uPlayScene�v�N���X�̃w�b�_�t�@�C��
//! @create		����@�T��
//! @date		17/04/07
===================================================================== */
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include "cocos2d.h"
#include "Gage.h"
#include "Food.h"
#include "Human.h"
#include "Player.h"

//box2d���g�����߂ɕK�v
#include "Box2D\Box2D.h" 
#include "GLES-Render.h"

// �萔
const int WINDOW_WIDTH = 960;						// ��ʂ̕�
const int WINDOW_HEIGHT = 640;						// ��ʂ̍���
const int NUM_TIME = 60;							// �P��̃Q�[������
const int INTERVAL_FOOD = 60 * 2;					// �H�ނ������Ă���Ԋu

// �N���X�̒�`
class PlayScene : public cocos2d::Scene
{
private:
	cocos2d::Sprite* m_pBack;			// �w�i
	cocos2d::Sprite* m_pStomach;		// ��

	cocos2d::Sprite* m_pTimeOneFloor;	// ��̈�
	cocos2d::Sprite* m_pTimeTenFloor;	// �\�̈�
	int m_countDown;					// �J�E���g�_�E��

	Gage* m_pGage;						//�Q�[�W
	Food* food;							//�H��
	Human* m_pHuman;					// �l��
	Player* m_pPlayer;					// �v���C���[

	b2World* m_pWorld;				//�������[���h
	b2Body* m_pBody;
	GLESDebugDraw* m_pDraw;			//�\���p�C���X�^���X

	float a;						//�_�~�[����

	int back_graund;				//BGM�̃^�O
	int heart;						//�S�����̃^�O

public:
	CREATE_FUNC(PlayScene);

	//�����V�X�e���̏�����
	void initPhysics();

	//�\���֐����I�[�o�[���C�h
	void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);

	//������
	virtual bool init();

	//�f�X�g���N�^
	~PlayScene();

	// �V�[�����쐬����
	static cocos2d::Scene* createScene();
	
	//�X�V����
	void update(float delta);

	// �H�ނ𗎂Ƃ�
	void FallFood();

	// �^�b�`�֌W�̊֐��錾
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);

	bool isCollision(cocos2d::Vec2 playerVec, cocos2d::Vec2 foodVec)
	{
		if ((playerVec.x < foodVec.x + 32) &&
			(playerVec.x + 96 > foodVec.x))
		{
			if ((playerVec.y < foodVec.y + 32) &&
				(playerVec.y + 96 > foodVec.y))
			{
				return true;
			}
		}

		return false;
	}

	// �V�[���ړ�
	void GameoverTransScene();				// �Q�[���I�[�o�[�V�[���Ɉړ�
	void ClearTransScene();					// �N���A�V�[���Ɉړ�

	// �ÓI�����o
	static int m_time;						// ����
	static bool put;
};