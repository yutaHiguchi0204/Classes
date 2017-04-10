//日付　04/09
//作者　井坂亘汰
//内容　食材の設定

#pragma once
#include "cocos2d.h"

//box2dを使うために必要
#include "Box2D\Box2D.h" 
#include "GLES-Render.h"

class Food : public cocos2d::Layer
{
private:
	int m_foodPoint;		// 食材のボリューム

public:
	CREATE_FUNC(Food);

	// 食材のボリュームを取得
	inline int GetFoodPoint()
	{
		return m_foodPoint;
	}

	//更新処理
	void update();

	//剛体の生成
	void texture(float dt, b2World* World, b2Body* Body);

	//物理システムの初期化
	void initPhysics();

	//初期化
	virtual bool init();

	//デストラクタ
	~Food();
};