#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"

class Background : public IGameObject
{
public:
	Background();
	~Background();
	bool Start();
	void Update();

	//座標を設定。
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	void SetScale(CVector3 sca)
	{
		m_scale = sca;
	}
	void Background::GetGhost() {
		
	}
private:
	prefab::CSkinModelRender* skinModelRender = nullptr; //スキンモデルレンダー
	prefab::CSoundSource* m_sound = nullptr;//ドットの音楽
	CVector3 m_position = CVector3::Zero; // 座標。
	CVector3 m_scale = CVector3::One; // スケール
	CPhysicsGhostObject m_ghost;							//ゴースト


	CPhysicsStaticObject m_physicsStaticObject; //静的物理オブジェクト
};

