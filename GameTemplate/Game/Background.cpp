#include "stdafx.h"
#include "Background.h"


Background::Background()
{
}


Background::~Background()
{
	DeleteGO(skinModelRender);
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


