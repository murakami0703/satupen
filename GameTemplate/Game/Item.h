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
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	EnState m_state = Wait;
};

