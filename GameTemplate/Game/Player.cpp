#include "stdafx.h"
#include "Player.h"
#include "GameData.h"

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
	/*m_animClips[enAnimationClip_idle].Load(L"animData/pltaiki.tka");
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_run].Load(L"animData/plrun.tka");
	m_animClips[enAnimationClip_run].SetLoopFlag(true);
	m_animClips[enAnimationClip_attack].Load(L"animData/plkougeki.tka");
	m_animClips[enAnimationClip_attack].SetLoopFlag(true);*/
	//スキンモデル
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Children/kodomo.cmo");
	//m_skinModelRender->PlayAnimation(0);
	m_scale = { 1.0f,1.0f,1.0f };
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetPosition(m_position);

	//ゲームデーターから体力を引っ張ってくる
	GameData* gamedata = GameData::GetInstance();
	m_Life = gamedata->Get_Life();
	//キャラコン
	m_charaCon.Init(
		20.0f,  //半径。
		68.0f,  //高さ。
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
	//moveVec.y -= 980.0f * GameTime().GetFrameDeltaTime();
	moveVec += cameraForward * stick.x * 100.0f;	//奥方向への移動速度を加算。
	


	m_position = m_charaCon.Execute(moveVec);
}

void Player::Animation()
{
		
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
	if (Pad(0).IsTrigger(enButtonA)) {
		moveVec *= 2.0f;
	}
	m_position = m_charaCon.Execute(moveVec);
}
void Player::Turn() {
	if (Turnflag == false) {
		if (Pad(0).IsTrigger(enButtonLB3)) {
			TurnTimer = 0;
			Turnflag = true;
		}
	}
	else {
		TurnTimer++;
		if (TurnTimer < TurnEnd) {
			CQuaternion Rot;
			Rot.SetRotation(CVector3::AxisY, 0.055f);
			m_rotation.Multiply(Rot);
		}
		else {
			Turnflag = false;
		}
	}
}
void Player::Update()
{
	Movestick();	//パッド移動
	Animation();	//アニメーション
	Rotation();		//回転
	Dash();		//走るよぉおお
	Turn();
	//移動と回転
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
