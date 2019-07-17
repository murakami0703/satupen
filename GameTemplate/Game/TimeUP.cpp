#include "stdafx.h"
#include "TimeUP.h"
#include"Result.h"


TimeUP::TimeUP()
{
}


TimeUP::~TimeUP()
{
	//DeleteGO(m_sprite);
	DeleteGO(m_sprite2);

	DeleteGO(m_sound);
}
bool TimeUP::Start()
{

	//かばー
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/Time UP/Time UP2.dds", 1280.0f, 720.0f);

	//タイムあっぷ
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/Time UP/Time UP.dds", 400.0f, 110.0f);
	m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	//サウンド
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/hoissuru.wav");
	m_sound->Play(false);
	m_sound->SetVolume(0.5f);
	return true;
}
void TimeUP::Update()
{
	switch (en_Start)
	{
	case TimeUP::en_Start:
	{
		CVector3 MOZI = m_sprite2->GetPosition();
		m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,TUP });
		TUP += 0.01;
		if (TUP >= 1.0f) {
			TUP = 1.0f;
		}
		break;
	}
	}
	if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Result>(0, "titel");
		DeleteGO(this);
	}
}