#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"
class Player : public IGameObject
{
	static Player* m_instance;

public:
	Player();
	~Player();
	//行動状態
	enum EnState {
		Estate_idle,	//待機
		Estate_move,	//行動中
		Estate_jump,	//行動中
		Estate_pre,		//予備
		Estate_attack,		//飛ばした
	};
	//アニメーション
	enum EnAnimationClip {
		enAnimationClip_idle, //待機
		enAnimationClip_walk,  //歩き
		enAnimationClip_jump,  //ジャンプ
		enAnimationClip_pre,  //予備
		enAnimationClip_attack, //飛ばした
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

	bool IsDash() const		//	ダッシュ判定
	{
		return m_isDash;
	}
	bool IsSetup() const	//	構え判定
	{
		return m_isSet;
	}

private:
	void Movestick();	//パッド移動
	void Animation();	//アニメーション
	void Rotation();	//回転
	void Dash();		//走るよぉおお
	void Turn();		//180°回転
	void Jump();		//ジャンプします
	void yobi();		//構えるよぉ

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	prefab::CSoundSource* m_sound = nullptr;//歩く音

	CVector3 m_oldpos = CVector3::Zero;//最初に追った場所。
	CVector3 m_position = CVector3::Zero;  // 座標。
	CQuaternion m_rotation = CQuaternion::Identity;  //回転。
	CVector3 m_scale = CVector3::Zero;  // スケール
	CVector3 moveVec = CVector3::Zero;  //移動速度
	CVector3 stick = CVector3::Zero;    //スティック
	CCharacterController m_charaCon;    //キャラコン

	EnState m_state = Estate_idle;							//状態
	CAnimationClip  m_animClips[enAnimationClip_Num];		//アニメーション

	//移動関連
	const float movespeed = 30.0f;							//移動速度
	//回転
	bool Turnflag = false;									//180°回転フラグ
	int TurnTimer = 0;										//回転タイマー
	const float  TurnEnd = 60.0f;							//回転終了までの時間

	bool m_isDash = false;									//ダッシュ判定
	bool m_isSet = false;									//構え判定

};

