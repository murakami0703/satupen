#include "stdafx.h"
#include "OP.h"
#include"OP2.h"
#include"OPsound.h"

OP::OP()
{
}


OP::~OP()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite2);
}
bool OP::Start()
{
	NewGO<OPsound>(0, "OPsound");
	//始めオープニング。
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/OP/aa.dds",1280.0f,720.0f);
	//言葉
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/OP/27916828.dds", 500.0f, 200.0f);
	m_position={0.0f, 50.0f, 0.0f};
	m_sprite2->SetPosition(m_position);
	m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,.0f });

	
	return true;
}

void OP::Update()
{
	switch (en_Start)
	{
	case OP::en_Start:
	{
			CVector3 MOZI = m_sprite2->GetPosition();
			m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,MOZI1 });
			MOZI1 += 0.01;
			if (MOZI1 >= 1.0f) {
				MOZI1 = 1.0f;
			}
			break;
	}
	
	}

	if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<OP2>(0, "op2");
		DeleteGO(this);
	}

}
