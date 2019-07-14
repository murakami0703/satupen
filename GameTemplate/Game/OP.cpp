#include "stdafx.h"
#include "OP.h"


OP::OP()
{
}


OP::~OP()
{
}
bool OP::Start()
{
	//始めオープニング。
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/OP/aa.dds",1280.0f,720.0f);
	//言葉
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/OP/27916828.dds", 500.0f, 200.0f);
	m_position={0.0f, 50.0f, 0.0f};
	m_sprite2->SetPosition(m_position);


	//サウンド
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/game_maoudamashii_8_orgel09.wav");
	m_sound->Play(true);
	m_sound->SetVolume(0.5f);
	return true;
}

void OP::Update()
{
	switch (en_Start)
	{
		CVector3 MOZI = m_sprite2->GetPosition();
		m_sprite2->SetMulColor({1.0f,1.0f,1.0f,MOZI1});
		MOZI1 += 0.05;
		if (MOZI1 >= 1.0f) {
			MOZI1 = 1.0f;
		}
		break;
	/*case OP::en_Start:
	{
		break;
	}
	case OP::en_Start2:
	{
		break;
	}
	case OP::en_Start3:
	{
		break;
	}*/
	
	}
}
