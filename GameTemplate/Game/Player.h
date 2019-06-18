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
	CVector3 Player::Getm_stick() {
		return stick;
	}
private:
	void Move();	//十字キー移動
	void Movestick();	//パッド移動
	void Animation();	//アニメーション
	void Rotation();	//回転
	void Dash();		//走るよぉおお
	void Attack();		//攻撃ﾀﾞﾖ

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero; // 座標。
	CQuaternion m_rotation = CQuaternion::Identity; //回転。
	CVector3 m_scale = CVector3::Zero; // 座標。
	CQuaternion qrot = CQuaternion::Identity; //スティック用
	CVector3 moveVec = CVector3::Zero; //移動速度
	CVector3 stick = CVector3::Zero;//スティック
	CCharacterController m_charaCon; //キャラコン

	CAnimationClip  m_animClips[enAnimationClip_Num];//アニメーション
	//移動関連
	const float movespeed = 30.0f;
	//攻撃関連
	EnAttackItem m_attackstate = Estate_Wait;	//攻撃状態
};

