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
	skinModelRender->Init(L"modelData/aaaaaaa.cmo", nullptr, 0);
	CVector3 scle = { 50.0f,50.0f,50.0f };
	skinModelRender->SetScale(scle);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	CVector3 pos = { 0.0f, 3000.0f, 0.0f };
	skinModelRender->SetPosition(pos);

	// CPhysicsStaticObjectの初期化
	m_physicsStaticObject.CreateMesh(pos, CQuaternion::Identity, scle, skinModelRender);

	return true;
}
void Background::Update()
{

}


