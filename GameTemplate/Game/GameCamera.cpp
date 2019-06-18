#include "stdafx.h"
#include "Player.h"
#include "GameCamera.h"


GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}

bool GameCamera::Start()
{
	//ニアクリップとファークリップの設定。
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(15000.0f);
	//カメラを設定。

	//ベクトルの設定
	CameraPos.Set(0.0f, 70.0f, -100.0f);
	return true;
}

void GameCamera::Update()
{
	//カメラの更新
	//プレイヤーの向きに合わせて動くぅ
	Player* player = FindGO<Player>("player");
	CVector3 target = player->Getm_Position();

	CVector3 st = player->Getm_stick();
	CVector3 CameraPosOld = CameraPos;
	//Y軸周りの回転
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * st.z);
	qRot.Multiply(CameraPos);

	CVector3 pos = target + CameraPos;
	//メインカメラに注視点と視点を設定する。
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);
	//カメラの更新
	MainCamera().Update();

}
