#pragma once

#include "tkEngine/physics/tkPhysicsGhostObject.h"

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
	prefab::CSoundSource* m_sound = nullptr;//ペンを投げる音を鳴らす
	CVector3 m_position = CVector3::Zero;					// 座標。
	CQuaternion m_rotation = CQuaternion::Identity;			//回転。
	CPhysicsGhostObject m_ghost;							//ゴースト
	CVector3 m_scale = CVector3::Zero;						// スケール


	const float moveSpeed = 600.0f;		//移動速度
	CVector3 P_target = CVector3::Zero;	//worldPosを入れます
	CVector3 diff = CVector3::Zero;		//ベクトル計算用
	bool dathflag = false;				//当たったら消えるフラグ
	bool keisannflag = false;			//一度きりの方向計算フラグ
	int m_timer = 0;					//弾消し用タイマー
	const float pendelete = 150.0f;		//弾を消すまでの時間
	CCharacterController m_charaCon;	 //キャラコン

	int Timer = 0;
	const int characontime = 30;
};

