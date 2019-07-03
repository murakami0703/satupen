#include "stdafx.h"
#include "Result.h"
#include "Game.h"

Result::Result()
{
}


Result::~Result()
{
	DeleteGO(m_sprite); //�w�i
	DeleteGO(m_sprite1);//�����@250*150
	DeleteGO(m_sprite2);//�ߐl�x�@330*150
	DeleteGO(m_sprite3);//Tti
	DeleteGO(m_sprite4);//ti2
	DeleteGO(m_sprite5);//�P�l�x�@330*150
	DeleteGO(m_sprite6);//ZH
	DeleteGO(m_sprite7);//���@1280*720
	DeleteGO(m_sprite8);//���Ȃ��́@400*150

}
bool Result::Start()
{
	//�X�v���C�g�������@�@�w�i
	m_sprite = NewGO<prefab::CSpriteRender>(1);
	m_sprite->Init(L"sprite/Result/RH.dds", 1280.0f, 720.0f);

	//����
	m_sprite1 = NewGO<prefab::CSpriteRender>(1);
	m_sprite1->Init(L"sprite/Result/sougou.dds", 250.0f,150.0f);
	m_postion = { 0.0f,400.0f,0.0f };
	m_sprite1->SetPosition(m_postion);
	//m_sprite1->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	
	//�ߐl�x
	m_sprite2 = NewGO<prefab::CSpriteRender>(1);
	m_sprite2->Init(L"sprite/Result/tumido.dds", 330.0f, 150.0f);
	m_postion = { -800.0f,120.0f,0.0f };
	m_sprite2->SetPosition(m_postion);
	//m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//Tti
	m_sprite3 = NewGO<prefab::CSpriteRender>(1);
	m_sprite3->Init(L"sprite/Result/Tti.dds", 1280.0f, 720.0f);
	m_postion = { 0.0f,0.0f,0.0f };
	m_sprite3->SetPosition(m_postion);
	m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//ti2
	m_sprite4 = NewGO<prefab::CSpriteRender>(1);
	m_sprite4->Init(L"sprite/Result/ti2.dds", 1280.0f, 720.0f);
	m_postion = { 0.0f,0.0f,0.0f };
	m_sprite4->SetPosition(m_postion);
	m_sprite4->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//�P�l�x
	m_sprite5 = NewGO<prefab::CSpriteRender>(1);
	m_sprite5->Init(L"sprite/Result/zennindo.dds", 330.0f, 150.0f);
	m_postion = { -800.0f,-80.0f,0.0f };
	m_sprite5->SetPosition(m_postion);
	//m_sprite5->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//ZH
	m_sprite6 = NewGO<prefab::CSpriteRender>(1);
	m_sprite6->Init(L"sprite/Result/ZH.dds", 1280.0f, 720.0f);
	m_postion = { 0.0f,0.0f,0.0f };
	m_sprite6->SetPosition(m_postion);
	m_sprite6->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//��
	m_sprite7 = NewGO<prefab::CSpriteRender>(1);
	m_sprite7->Init(L"sprite/Result/hikari.dds", 1280.0f, 720.0f);
	m_postion = { 0.0f,0.0f,0.0f };
	m_sprite7->SetPosition(m_postion);
	m_sprite7->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

	//���Ȃ�
	m_sprite8 = NewGO<prefab::CSpriteRender>(1);
	m_sprite8->Init(L"sprite/Result/anata.dds", 400.0f, 150.0f);
	m_postion = { -400.0f,-300.0f,0.0f };
	m_sprite8->SetPosition(m_postion);
	//m_sprite8->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	return true;
}
void Result::Update()
{
	switch (m_start)
    {
	case Result::enStart_new:
	{
		//����
		CVector3 soupos = m_sprite1->GetPosition();//����

		if (soupos.y >= movepos.y) {
			soupos.y -= 1.0f;
		}
		else {
			soupos = movepos;
			m_start = enStart_1;
		}
		m_sprite1->SetPosition(soupos);
		break;
	}

	case Result::enStart_1:
	{
		//�ߓx
		CVector3 tumipos = m_sprite2->GetPosition();//�ߓx
		if (tumipos.x <= tumipos2.x) {

			tumipos.x += 3.0f;
		}
		else {
			tumipos = tumipos2;
			m_start = enStart_2;
		}
		m_sprite2->SetPosition(tumipos);
		break;
	}
	case Result::enStart_2:
	{
		//�P�l�x
		CVector3 zenpos = m_sprite5->GetPosition();//�P�l�x
		if (zenpos.x <= zenpos2.x) {
			zenpos.x += 3.0f;
		}
		else {
			zenpos = zenpos2;
			m_start = enStart_3;
		}
		m_sprite5->SetPosition(zenpos);
		break;
	}

	case Result::enStart_3:
	{
		////��
		CVector3 Ttipos = m_sprite3->GetPosition();//�ߐl�̌�
		m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
		m_start = enStart_4;
		
	}
	case Result::enStart_4:
	{
		//��
		CVector3 ZH = m_sprite6->GetPosition();//�P�l�̌�
		m_sprite6->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });
		m_start = enStart_5;
	}
	case Result::enStart_5:
	{
		////�߂̂��
		//wchar_t text[256];
		//int x = +10;
		//swprintf(text, L"\n+%02d", x);
		//m_font->SetText(text);
		//m_font->SetPosition({ 250.0f, 120.0f });
		//m_font->SetPivot({ 0.0f, 0.0f });///�E��

	}
    }
	
}