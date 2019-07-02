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

	return true;
}
void Background::Update()
{
	skinModelRender->SetPosition(m_position);

}


