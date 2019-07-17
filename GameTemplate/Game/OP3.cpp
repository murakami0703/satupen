#include "stdafx.h"
#include "OP3.h"
#include"Game.h"
#include"OPsound.h"
#include"GamePad.h"


OP3::OP3()
{
}


OP3::~OP3()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite1);
	DeleteGO(m_sprite2);
	DeleteGO(m_sprite3);
	DeleteGO(m_sprite4);
	DeleteGO(m_sprite5);

	OPsound* op = OPsound::GetInstance();
	DeleteGO(op);
	//DeleteGO(m_sound);


}
bool OP3::Start()
{
	
	//はじめのオープニング3
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/OP/op3haikei.dds", 1280.0f, 720.0f);

	//人
	m_sprite1 = NewGO<prefab::CSpriteRender>(0);
	m_sprite1->Init(L"sprite/OP/op3hito.dds", 350.0f, 450.0f);
	m_position = { 0.0f,-150.0f,0.0f };
	m_sprite1->SetPosition(m_position);
	m_sprite1->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//penn
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/OP/op3pen.dds", 250.0f, 400.0f);
	m_position = { 210.0f,-130.0f,0.0f };
	m_sprite2->SetPosition(m_position);
	m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });

	//こうして彼の戦いが始まります
	m_sprite3 = NewGO<prefab::CSpriteRender>(0);
	m_sprite3->Init(L"sprite/OP/op3kousite1.dds", 250.0f, 250.0f);
	m_position = { -520.0f,200.0f,0.0f };
	m_sprite3->SetPosition(m_position);
	m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//皆様
	m_sprite4 = NewGO<prefab::CSpriteRender>(0);
	m_sprite4->Init(L"sprite/OP/op3kousite2.dds", 250.0f, 300.0f);
	m_position = { 500.0f,-150.0f,0.0f };
	m_sprite4->SetPosition(m_position);
	m_sprite4->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

    //緑色の血
	m_sprite5 = NewGO<prefab::CSpriteRender>(0);
	m_sprite5->Init(L"sprite/OP/op3ti.dds", 1280.0f, 720.0f);
	m_position = { 0.0f,0.0f,0.0f };
	m_sprite5->SetPosition(m_position);
	m_sprite5->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });


	return true;
}
void OP3::Update()
{
	switch (m_start)
	{
	case OP3::en_Start: {
		//これは文字
		CVector3 OP3MOZI = m_sprite3->GetPosition();
		m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,OP3mozi });
		OP3mozi += 0.01f;
		if (OP3mozi >= 1.0f) {
			OP3mozi = 1.0f;
			m_start = en_Start2;
		}
		break;
	}
	case OP3::en_Start2:{
		CVector3 HI = m_sprite1->GetPosition();
		m_sprite1->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
		m_start = en_Start3;
		break;
	}
	case OP3::en_Start3:{
		CVector3 HI = m_sprite5->GetPosition();
		m_sprite5->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
		m_start = en_Start4;
		break;
	}
	case OP3::en_Start4:{

		//これは文字2
		CVector3 OP3MOZI = m_sprite4->GetPosition();
		m_sprite4->SetMulColor({ 1.0f,1.0f,1.0f,OP3mozi2 });
		OP3mozi2 += 0.01f;
		if (OP3mozi2 >= 1.0f) {
			OP3mozi2 = 1.0f;
			m_start = en_Start2;
		}
		break;

	}

	}

		if (Pad(0).IsTrigger(enButtonStart)) {
			NewGO<GamePad>(0, "gamepad");
			DeleteGO(this);

		}
}