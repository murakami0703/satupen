#include "stdafx.h"
#include "OP2.h"
#include"OP3.h"


OP2::OP2()
{
}


OP2::~OP2()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite1);
	DeleteGO(m_sprite2);
	DeleteGO(m_sprite3);
	DeleteGO(m_sprite4);
}
bool OP2::Start()
{
	//はじめのオープニング２
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/OP/op2.dds",1280.0f,720.0f);

	//言葉
	m_sprite1 = NewGO<prefab::CSpriteRender>(0);
	m_sprite1->Init(L"sprite/OP/op2sore.dds", 350.0f, 200.0f);
	m_position = { -280.0f,200.0f,0.0f };
	m_sprite1->SetPosition(m_position);
	m_sprite1->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//ペン
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/OP/op2pen.dds", 300.0f, 400.0f);
	m_position = { 300.0f,-30.0f,0.0f };
	m_sprite2->SetPosition(m_position);
	m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	
	//言葉２
	m_sprite3 = NewGO<prefab::CSpriteRender>(0);
	m_sprite3->Init(L"sprite/OP/penOP2.dds", 600.0f, 100.0f);
	m_position = { -300.0f,0.0f,0.0f };
	m_sprite3->SetPosition(m_position);
	m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//びっくりいいいい
	m_sprite4 = NewGO<prefab::CSpriteRender>(0);
	m_sprite4->Init(L"sprite/OP/bikkuri.dds", 100.0f, 150.0f);
	m_position = { -200.0f,-100.0f,0.0f };
	m_sprite4->SetPosition(m_position);
	m_sprite4->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	return true;

}

void OP2::Update()
{
	switch (m_Star)
	{

	case OP2::en_Start:
	{
		//これは文字
		CVector3 OP2MOZI = m_sprite1->GetPosition();
		m_sprite1->SetMulColor({ 1.0f,1.0f,1.0f,OP2mozi });
		OP2mozi += 0.01f;
		if (OP2mozi >= 1.0f) {
			OP2mozi = 1.0f;
			m_Star = en_Start2;
		}
		break;
	}

	case OP2::en_Start2:
	{
		//これはペン
		CVector3 Pe= m_sprite2->GetPosition();
		m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });

		m_Star = en_Start3;
		break;
	}

	case OP2::en_Start3:
	{
		//びっくりをだす
		CVector3 Bi = m_sprite4->GetPosition();
		m_sprite4->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });

		m_Star = en_Start4;
		break;
	}

	case OP2::en_Start4:
	{
		//これは文字
		CVector3 OP2MOZI2 = m_sprite3->GetPosition();
		m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,OP2mozi2 });
		OP2mozi2 += 0.01f;
		if (OP2mozi2 >= 1.0f) {
			OP2mozi2 = 1.0f;
		}

		break;
	}

	}

	if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<OP3>(0, "op3");
		DeleteGO(this);
	}

}