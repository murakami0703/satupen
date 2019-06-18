#include "stdafx.h"
#include "Player.h"
#include "Pen.h"

Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
}


bool Player::Start()
{
	//アニメーション
	m_animClips[enAnimationClip_idle].Load(L"animData/unityChan/idle.tka");
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_run].Load(L"animData/unityChan/run.tka");
	m_animClips[enAnimationClip_run].SetLoopFlag(true);
	m_animClips[enAnimationClip_walk].Load(L"animData/unityChan/walk.tka");
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);

	//スキンモデル
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo", m_animClips, enAnimationClip_Num, enFbxUpAxisY);
	m_skinModelRender->PlayAnimation(0);
	m_scale = { 0.3f,0.3f,0.3f };
	m_skinModelRender->SetScale(m_scale);
	//キャラコン
	m_charaCon.Init(
		20.0f,  //半径。
		68.0f,  //高さ。
		m_position //初期座標。
	);
	return true;
}

void Player::Move()
{
	moveVec.x = 0.0f;
	moveVec.z = 0.0f;
	//十字ボタン移動
	if (Pad(0).IsPress(enButtonUp)) {
		moveVec.z -= movespeed;
	}
	if (Pad(0).IsPress(enButtonDown)) {
		moveVec.z += movespeed;

	}
	if (Pad(0).IsPress(enButtonLeft)) {
		moveVec.x += movespeed;

	}
	if (Pad(0).IsPress(enButtonRight)) {
		moveVec.x -= movespeed;

	}
	m_position = m_charaCon.Execute(moveVec);

}

void Player::Movestick()
{
	//スティック移動ぉぉぉぉ
	stick.x = Pad(0).GetLStickYF();
	stick.y = 0.0f;
	stick.z = Pad(0).GetLStickXF();

	//カメラの前方方向と右方向を取得。
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ平面での前方方向、右方向に変換する。
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();
	//XZ成分の移動速度をクリア。
	moveVec.x = 0.0f;
	moveVec.z = 0.0f;
	//moveVec.y -= 980.0f * GameTime().GetFrameDeltaTime();
	moveVec += cameraForward * stick.x * 15.0f;	//奥方向への移動速度を加算。
	moveVec += cameraRight * stick.z * 15.0f;		//右方向への移動速度を加算。


	m_position = m_charaCon.Execute(moveVec);
}

void Player::Animation()
{
	//アニメーション
		if (Pad(0).IsPress(enButtonRight)||Pad(0).IsPress(enButtonLeft)) {
			m_skinModelRender->PlayAnimation(enAnimationClip_walk, 0.1f);
		}
		else if (Pad(0).IsPress(enButtonLeft)) {
			m_skinModelRender->PlayAnimation(enAnimationClip_walk, 0.1f);
		}
		else if (Pad(0).IsPress(enButtonUp)) {
			m_skinModelRender->PlayAnimation(enAnimationClip_walk, 0.1f);
		}
		else if (Pad(0).IsPress(enButtonDown)) {
			m_skinModelRender->PlayAnimation(enAnimationClip_walk, 0.1f);
		}
		else {
			m_skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
		
}

void Player::Rotation()
{
	//回転
	//十字ボタン
	//if (Pad(0).IsPress(enButtonRight)) {
	//	m_rotation.SetRotationDeg(CVector3::AxisY, -90.0f);
	//}
	//else if (Pad(0).IsPress(enButtonLeft)) {
	//	m_rotation.SetRotationDeg(CVector3::AxisY, 90.0f);
	//}
	//else if (Pad(0).IsPress(enButtonUp)) {
	//	m_rotation.SetRotationDeg(CVector3::AxisY, 180.0f);
	//}
	//else if (Pad(0).IsPress(enButtonDown)) {
	//	m_rotation.SetRotationDeg(CVector3::AxisY, 0.0f);
	//}
	//スティック
	if (fabsf(moveVec.x) < 0.001f
		&& fabsf(moveVec.z) < 0.001f) {
		return;
	}
	if (stick.x >= 0.0f) {
		float angle = atan2(moveVec.x, moveVec.z);
		m_rotation.SetRotation(CVector3::AxisY, angle);
	}
	if (stick.z <= 0.5f && stick.z >= -0.5f) {
		float angle = atan2(moveVec.x, moveVec.z);
		m_rotation.SetRotation(CVector3::AxisY, angle);

	}

}
void Player::Dash() {
	//走るよぉおお
	if (Pad(0).IsTrigger(enButtonA)) {
		moveVec *= 2.0f;
	}
	m_position = m_charaCon.Execute(moveVec);

}
void Player::Attack()
{
	//攻撃ﾀﾞﾖ
	if (Pad(0).IsTrigger(enButtonB)) {
		NewGO<Pen>(0, "pen");
	}
}
void Player::Update()
{
	//Move();			//十字キー移動
	Movestick();	//パッド移動
	Animation();	//アニメーション
	Rotation();		//回転
	Dash();		//走るよぉおお
	Attack();	//ペン投げる

	//移動と回転
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
