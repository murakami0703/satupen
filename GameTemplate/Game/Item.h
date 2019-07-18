#pragma once
class Item : public IGameObject
{
public:
	Item();
	~Item();
	enum EnState {
		Wait,	//置かれたまま
		Follow,	//プレイヤーに集まるよ
	};
	bool Start();
	void Update();
	//座標を設定。
	void SetPosition(CVector3 pos)
	{
		m_position = pos;
	}
	//回転を設定。
	void SetRotation(CQuaternion rot)
	{
		m_rotation = rot;
	}
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	prefab::CSoundSource* m_sound = nullptr;//アイテムを拾った音。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity;			//回転。
	EnState m_state = Wait;

	const float itemlength = 100.0f;
	const float itemspeed = 8.0f;
	const float itemrecovery = 3.0f;
}; 

