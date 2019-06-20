#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"
class Player : public IGameObject
{
	static Player* m_instance;

public:
	Player();
	~Player();
	enum EnState {
		Estate_idle,
		Estate_move,
		Estate_attack,
	};
	//アニメーション
	enum EnAnimationClip {
		enAnimationClip_idle, //待機
		enAnimationClip_walk,  //走り
		enAnimationClip_attack, //攻撃
		enAnimationClip_Num,  //アニメーションクリップ
	};

	bool Start();
	void Update();

	//ポジションを返す関数
	CVector3 Player::Getm_Position() {
		return m_position;
	}
	//回転を返す関数
	CQuaternion Player::Getm_Rotation() {
		return m_rotation;
	}
	//インスタンスの取得
	static Player* Player::GetInstance() {
		return m_instance;
	}

private:
	void Movestick();	//パッド移動
	void Animation();	//アニメーション
	void Rotation();	//回転
	void Dash();		//走るよぉおお
	void Turn();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::Zero; // スケール
	CVector3 moveVec = CVector3::Zero; //移動速度
	CVector3 stick = CVector3::Zero;//スティック
	CCharacterController m_charaCon; //キャラコン

	CAnimationClip  m_animClips[enAnimationClip_Num];//アニメーション

	//移動関連
	const float movespeed = 30.0f;
	//回転
	bool Turnflag = false;
	int TurnTimer = 0;
	const float keisann = 180.0f / TurnEnd;
	const float  TurnEnd = 60.0f;

};

