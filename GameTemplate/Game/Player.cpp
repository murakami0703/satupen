#include "stdafx.h"
#include "Player.h"

Player* Player::m_instance = nullptr;

Player::Player()
{
	if (m_instance != nullptr) {
		std::abort(); //すでに出ているためクラッシュ
	}

	//このインスタンスを唯一のインスタンスとして記録する
	m_instance = this;

}


Player::~Player()
{
	//インスタンスが破棄されたので、nullptrを代入
	m_instance = nullptr;


	DeleteGO(m_skinModelRender);
}


bool Player::Start()
{
	//アニメーション
	m_animClips[enAnimationClip_idle].Load(L"animData/playeridel.tka"); //待機
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_walk].Load(L"animData/playerwalk.tka"); //歩き
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);
	m_animClips[enAnimationClip_jump].Load(L"animData/playerjump.tka"); //歩き
	m_animClips[enAnimationClip_pre].Load(L"animData/Kamae.tka"); //予備

	m_animClips[enAnimationClip_attack].Load(L"animData/Nageru.tka"); //攻撃
	//スキンモデル
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Children/kodomo.cmo", m_animClips, enAnimationClip_Num);
	m_skinModelRender->PlayAnimation(1);
	m_scale = { 1.0f,1.0f,1.0f };
	m_position = { 0.0f,0.0f,0.0f };
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetPosition(m_position);

	//キャラコン
	m_charaCon.Init(
		10.0f,  //半径。
		15.0f,  //高さ。
		m_position //初期座標。
	);
	return true;
}

void Player::Movestick()
{

	//移動
	stick.x = Pad(0).GetLStickYF();
	stick.y = 0.0f;
	stick.z = Pad(0).GetLStickXF();


	//カメラの前方方向と右方向を取得。
	CVector3 cameraForward = MainCamera().GetForward();
	//CVector3 cameraRight = MainCamera().GetRight();
	//XZ平面での前方方向、右方向に変換する。
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	
	//XZ成分の移動速度をクリア。
	moveVec.x = 0.0f;
	moveVec.z = 0.0f;
	moveVec += cameraForward * stick.x * 100.0f;	//奥方向への移動速度を加算。

	//地面上かつ予備動作していないとき
	if (m_charaCon.IsOnGround() == true && m_isSet == false) {
			if (fabsf(stick.x) < 0.001f && fabsf(stick.z) < 0.001f) {
				//パッド入力がないので待機アニメショ
				m_state = Estate_idle;
				return;
			}
			else {
				m_state = Estate_move;
		}
	}
	//重力
	moveVec.y -= 2.0f;
	m_position = m_charaCon.Execute(moveVec);
	
}

void Player::Animation()
{
	if (m_state == Estate_idle) {
		m_skinModelRender->PlayAnimation(0);
	}
	else if (m_state == Estate_move) {
		m_skinModelRender->PlayAnimation(1);
	}
	else if (m_state == Estate_jump) {
		m_skinModelRender->PlayAnimation(2, 0.3f);
	}
	else if (m_state == Estate_pre) {
		m_skinModelRender->PlayAnimation(3, 0.3f);

	}
}

void Player::Rotation()
{
	//回転
	CQuaternion qAddRot;
	qAddRot.SetRotation(CVector3::AxisY, Pad(0).GetLStickXF() * 0.05f);
	m_rotation.Multiply(qAddRot);

}
void Player::Dash() {
	//走るよぉおお
	if (Pad(0).IsPress(enButtonA)) {
		m_isDash = true;
		moveVec *= 2.0f;
		CVector3 old = m_position - m_oldpos;
		old.Normalize();
		if (old.x>0.03f||old.z>0.03f) {
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/Mwalk.wav");
			m_sound->Play(false);
			m_sound->SetVolume(0.5f);
		}
	}
	else {
		m_isDash = false;

	}
	m_position = m_charaCon.Execute(moveVec);
}
void Player::Turn() {
	//180°回転
	if (Turnflag == false) {	
		//ターン中じゃないときに回転可
		if (Pad(0).IsTrigger(enButtonLB3)) {
			TurnTimer = 0;
			Turnflag = true;
		}
	}
	else {
		TurnTimer++;
		if (TurnTimer < TurnEnd) {
			//グルグルします。。
			CQuaternion Rot;
			Rot.SetRotation(CVector3::AxisY, 0.055f);
			m_rotation.Multiply(Rot);
		}
		else {
			Turnflag = false;
		}
	}
}
void Player::Jump()
{
	//ジャンプします。
	if (m_charaCon.IsOnGround() == true) {
		if (Pad(0).IsTrigger(enButtonB) ) {
			m_state = Estate_jump;
			moveVec.y = 50.0f;
		}
	}
	m_position = m_charaCon.Execute(moveVec);
}
void Player::yobi() {
	if (Pad(0).IsPress(enButtonLB1)) {
		//攻撃しようとしているぅアニメ署
		//構えて
		m_state = Estate_pre;
		m_isSet = true;
	}
	else {
		m_isSet = false;
	}

}
void Player::Update()
{
	Movestick();	//パッド移動
	Animation();	//アニメーション
	Rotation();		//回転
	Dash();			//走るよぉおお
	Turn();			//180°回転
	Jump();			//ジャンプします。
	yobi();			//構えます

	//移動と回転
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
