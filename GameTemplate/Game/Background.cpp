#include "stdafx.h"
#include "Background.h"


Background::Background()
{
}


Background::~Background()
{
	TK_LOG("~Background()");
	DeleteGO(skinModelRender);

	DeleteGO(m_sound);
}

bool Background::Start()
{
	//マップのロード
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/ste/sute.cmo");
	skinModelRender->SetScale(m_scale);
	skinModelRender->SetPosition(m_position);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	//ゴーストの初期化
	//ゴーストのワイヤーフレーム表示を有効にする。
	//PhysicsWorld().SetDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);
	//ボックス形状のゴーストを作成する。
	m_ghost.CreateBox(
		{ 0.0f, 0.0f, 0.0f },	//第一引数は座標。
		CQuaternion::Identity,		//第二引数は回転クォータニオン。
		{ 600.0f, 200.0f, 300.0f }	//第三引数はボックスのサイズ。
	);
	// CPhysicsStaticObjectの初期化
	m_physicsStaticObject.CreateMesh(m_position, CQuaternion::Identity, m_scale, skinModelRender);

	//音楽ドットの
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/tw088.wav");
	m_sound->Play(true);
	m_sound->SetVolume(0.5f);

	return true;
}
void Background::Update()
{
	skinModelRender->SetPosition(m_position);

}


