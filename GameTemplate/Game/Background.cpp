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
	//�}�b�v�̃��[�h
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/testback.cmo", nullptr, 0);
	CVector3 scle = { 1.0f,1.0f,1.0f };
	skinModelRender->SetScale(scle);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	CVector3 pos = { 0.0f, 0.0f, 0.0f };
	skinModelRender->SetPosition(pos);

	// CPhysicsStaticObject�̏�����
	m_physicsStaticObject.CreateMesh(pos, CQuaternion::Identity, scle, skinModelRender);

	return true;
}
void Background::Update()
{

}


