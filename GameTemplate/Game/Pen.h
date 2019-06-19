#pragma once
class Pen : public IGameObject
{
public:
	Pen();
	~Pen();
	bool Start();
	void Update();
private:

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::Zero; // スケール



	const float moveSpeed = 60.0f; //速度
	CVector3 buvec = CVector3::Zero;

	int m_timer = 0;
	bool keisannflag = false;
	const float pendelete = 150.0f; //玉を消すまでのタイマー
};

