#pragma once
class Window : public IGameObject
{
public:
	Window();
	~Window();

	bool Start();
	void Update();

	//座標を設定。
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	void SetRotation(CQuaternion rot)
	{
		m_rotation = rot;
	}
	void SetScale(CVector3 sca)
	{
		m_scale = sca;
	}

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	prefab::CSoundSource* m_sound = nullptr; //うたれたときの音
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::One; // スケール

	CPhysicsStaticObject m_physicsStaticObject; //静的物理オブジェクト

};

