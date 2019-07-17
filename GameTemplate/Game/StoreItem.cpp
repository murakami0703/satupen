#include "stdafx.h"
#include "StoreItem.h"
#include "Pen.h"

StoreItem::StoreItem()
{

}
StoreItem::~StoreItem()
{
	DeleteGO(m_skinModelRender);
}
bool StoreItem::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	switch (m_state)
	{
	case StoreItem::Apple:
		m_skinModelRender->Init(L"modelData/ste/store_item/Apple.cmo");
		break;
	case StoreItem::Big_black:
	m_skinModelRender->Init(L"modelData/ste/store_item/Big_black.cmo");
		break;
	case StoreItem::Big_rad:
	m_skinModelRender->Init(L"modelData/ste/store_item/Big_rad.cmo");
		break;
	case StoreItem::Blackstripe:
	m_skinModelRender->Init(L"modelData/ste/store_item/Blackstripe.cmo");
		break;
	case StoreItem::Blackteapot:
	m_skinModelRender->Init(L"modelData/ste/store_item/Blackteapot.cmo");
		break;
	case StoreItem::Bulegas:
	m_skinModelRender->Init(L"modelData/ste/store_item/Bulegas.cmo");
		break;
	case StoreItem::Buleteapot:
	m_skinModelRender->Init(L"modelData/ste/store_item/Buleteapot.cmo");
		break;
	case StoreItem::Chocodonatu:
	m_skinModelRender->Init(L"modelData/ste/store_item/Chocodonatu.cmo");
		break;
	case StoreItem::Currybread:
	m_skinModelRender->Init(L"modelData/ste/store_item/Currybread.cmo");
		break;
	case StoreItem::Donatu:
	m_skinModelRender->Init(L"modelData/ste/store_item/Donatu.cmo");
		break;
	case StoreItem::Dumpling:
	m_skinModelRender->Init(L"modelData/ste/store_item/Dumpling.cmo");
		break;
	case StoreItem::Eggbread:
	m_skinModelRender->Init(L"modelData/ste/store_item/Eggbread.cmo");
		break;
	case StoreItem::GGrapes:
	m_skinModelRender->Init(L"modelData/ste/store_item/GGrapes.cmo");
		break;
	case StoreItem::Goldring:
	m_skinModelRender->Init(L"modelData/ste/store_item/Goldring.cmo");
		break;
	case StoreItem::Grapes:
	m_skinModelRender->Init(L"modelData/ste/store_item/Grapes.cmo");
		break;
	case StoreItem::Greenteapot:
	m_skinModelRender->Init(L"modelData/ste/store_item/Greenteapot.cmo");
		break;
	case StoreItem::Konbu_onigiri:
	m_skinModelRender->Init(L"modelData/ste/store_item/Konbu_onigiri.cmo");
		break;
	case StoreItem::Matcha_ole:
	m_skinModelRender->Init(L"modelData/ste/store_item/Matcha_ole.cmo");
		break;
	case StoreItem::Mini_black:
	m_skinModelRender->Init(L"modelData/ste/store_item/Mini_black.cmo");
		break;
	case StoreItem::Mini_red:
	m_skinModelRender->Init(L"modelData/ste/store_item/Mini_red.cmo");
		break;
	case StoreItem::Muscat:
	m_skinModelRender->Init(L"modelData/ste/store_item/Muscat.cmo");
		break;
	case StoreItem::Orange:
	m_skinModelRender->Init(L"modelData/ste/store_item/Orange.cmo");
		break;
	case StoreItem::Orangegas:
	m_skinModelRender->Init(L"modelData/ste/store_item/Orangegas.cmo");
		break;
	case StoreItem::Orangestripe:
	m_skinModelRender->Init(L"modelData/ste/store_item/Orangestripe.cmo");
		break;
	case StoreItem::Pinkgas:
	m_skinModelRender->Init(L"modelData/ste/store_item/Pinkgas.cmo");
		break;
	case StoreItem::Redstripe:
	m_skinModelRender->Init(L"modelData/ste/store_item/Redstripe.cmo");
		break;
	case StoreItem::Skinring:
	m_skinModelRender->Init(L"modelData/ste/store_item/Skinring.cmo");
		break;
	case StoreItem::Strawberry_ole:
	m_skinModelRender->Init(L"modelData/ste/store_item/Strawberry_ole.cmo");
		break;
	case StoreItem::Ume_onigiri:
	m_skinModelRender->Init(L"modelData/ste/store_item/Ume_onigiri.cmo");
		break;
	case StoreItem::Yellowgas:
	m_skinModelRender->Init(L"modelData/ste/store_item/Yellowgas.cmo");
		break;
	case StoreItem::Yellowstripe:
	m_skinModelRender->Init(L"modelData/ste/store_item/Yellowstripe.cmo");
		break;
	case StoreItem::Yellowteapot:
	m_skinModelRender->Init(L"modelData/ste/store_item/Yellowteapot.cmo");
		break;
	}


	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetRotation(m_rotation);

	// CPhysicsStaticObject‚Ì‰Šú‰»
	m_physicsStaticObject.CreateMesh(m_position, CQuaternion::Identity, m_scale, m_skinModelRender);
	m_skinModelRender->SetShadowCasterFlag(true);

	return true;
}
void StoreItem::Update()
{
	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		if (diff.Length() < 20.0f) {
			//Œ‚‚½‚ê‚½....
			//ƒyƒ“‚àÁ‚¦‚ë
			//‚¤‚½‚ê‚½Žž‚Ì‰¹
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/MAuke.wav");
			m_sound->Play(false);
			m_sound->SetVolume(0.5f);
			pen->SetDeath();
			DeleteGO(this);
		}
		return true;
		});



	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(m_scale);
	m_skinModelRender->SetRotation(m_rotation);


}

