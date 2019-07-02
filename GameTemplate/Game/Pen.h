#pragma once
class Pen : public IGameObject
{
public:
	Pen();
	~Pen();
	bool Start();
	void Update();

	//ポジションを返す関数
	CVector3 Pen::Getm_Position() {
		return m_position;
	}
	//自分が消える関数
	int Pen::SetDeath() {
		dathflag = true;
		return 0;
	}
private:

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::Zero; // スケール


	const float moveSpeed = 200.0f; //速度
	CVector3 P_target = CVector3::Zero;
	CVector3 diff = CVector3::Zero;
	bool dathflag = false;		//当たったら消えるフラグ
	int m_timer = 0;
	bool keisannflag = false;
	const float pendelete = 150.0f; //玉を消すまでのタイマー
	CCharacterController m_charaCon; //キャラコン


};

