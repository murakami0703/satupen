#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/character/tkCharacterController.h"
class Player : public IGameObject
{
public:
	Player();
	~Player();
	enum EnState {
		Estate_idle,
		Estate_move,
		Estate_attack,
	};
	//攻撃
	enum EnAttackItem {
		Estate_Wait,	//何もしない
		Estate_Pen,		//ペン

	};
	//アニメーション
	enum EnAnimationClip {
		enAnimationClip_idle, //待機
		enAnimationClip_run,  //走り
		enAnimationClip_walk, //歩き
		enAnimationClip_Num,  //アニメーションクリップ
	};

	bool Start();
	void Update();

	//ポジションを返す関数
	CVector3 Player::Getm_Position() {
		return m_position;
	}
	//スティックの値を返す関数(カメラに使ってる）
	CQuaternion Player::Getm_Rotation() {
		return m_rotation;
	}
	//体力を返す関数
	int Player::Get_Life() {
		return m_Life;
	}

private:
	void Movestick();	//パッド移動
	void Animation();	//アニメーション
	void Rotation();	//回転
	void Dash();		//走るよぉおお

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::Zero; // スケール
	CVector3 moveVec = CVector3::Zero; //移動速度
	CVector3 stick = CVector3::Zero;//スティック
	CCharacterController m_charaCon; //キャラコン

	CAnimationClip  m_animClips[enAnimationClip_Num];//アニメーション

	int m_Life = 0; //自分の体力
	//移動関連
	const float movespeed = 30.0f;
	//攻撃関連
	EnAttackItem m_attackstate = Estate_Wait;	//攻撃状態
};

