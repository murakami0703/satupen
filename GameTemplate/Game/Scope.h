#pragma once
class Scope :public IGameObject
{
public:
	Scope();
	~Scope();
	bool Start();
	void Update();
	//ポジションを返す関数
	CVector3 Scope::Getm_Position() {
		return m_position;
	}
private:
	prefab::CSpriteRender* m_sprite;
	CVector3 m_position = CVector3::Zero; // 座標。
	CVector3 R_stick = CVector3::Zero; // スティック

};

