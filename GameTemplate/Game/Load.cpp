#include "stdafx.h"
#include "Load.h"
#include"Game.h"


Load::Load()
{
}


Load::~Load()
{
	DeleteGO(m_skinModel);
	DeleteGO(m_skinModel2);
}
bool Load::Start()
{
	//Loda‚Ì‰æ–Ê•‚¢‚â‚Â
	m_skinModel = NewGO<prefab::CSpriteRender>(0);
	m_skinModel->Init(L"sprite/Load/haikeii.dds",1280.0f,720.0f);

	//Load‚Ì•¶š
	m_skinModel2 = NewGO<prefab::CSpriteRender>(0);
	m_skinModel2->Init(L"sprite/Load/Load.dds", 550.0f, 250.0f);
	m_position={ -300.0f,-210.0f ,0.0f};
	m_skinModel2->SetPosition(m_position);
	//m_skinModel2->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	/*CVector2 screenPos;
	MainCamera().CalcScreenPositionFromWorldPosition(screenPos, m_position);*/

	return  true;

}
void Load::Update()
{

	switch (m_state)
	{
	case Load::en_Start:
	{
		CVector3 saturikuH = m_skinModel2->GetPosition();
		m_skinModel2->SetMulColor({ 1.0,1.0f,1.0f,MP1 });
		MP1 += 0.005f;
		if (MP1 >= 1.0f) {
			MP1= 10.0f;
		}
	}
		break;
	}

	/*if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Game>(0, "game");
		DeleteGO(this);

	}*/
}