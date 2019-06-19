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
	//CameraPos.Set(0.0f, 20.0f, -50.0f);
	return true;
}

void GameCamera::Update()
{
	//カメラの更新
	//プレイヤーの向きに合わせて動くぅ
	Player* player = FindGO<Player>("player");
	CVector3 target = player->Getm_Position();
	CVector3 vBase = { 0.0f,0.0f,1.0f };
	CVector3 vyoBase = { -1.0f,0.0f,0.0f };
	CQuaternion p_qRot = player->Getm_Rotation();
	p_qRot.Apply(vBase);
	p_qRot.Apply(vyoBase);
	CVector3 vpos = vBase * -50.0f;

	CVector3 pos = vpos + target;
	pos.y = pos.y + 20.0f;
	target.y = 30.0f;
	//メインカメラに注視点と視点を設定する。
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);
	
	//カメラの更新
	MainCamera().Update();
	CVector3 cameraposOld = CameraPos;
}
