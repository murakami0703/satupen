#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"


GameOver::GameOver()
{
}


GameOver::~GameOver()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite2);
}
bool GameOver::Start()
{
	//ê^Ç¡à√ÇÃÇ‚Ç¬
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/GameOver/GameOver2.dds", 1280.0f, 720.0f);

	//åæót
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/GameOver/GameOver.dds", 550.0f, 100.0f);
	
	return true;
}
void GameOver::Update()
{
	switch (en_Start)
	{
	case GameOver::en_Start:
	{
		CVector3 MOZI = m_sprite2->GetPosition();
		m_sprite2->SetMulColor({ 1.0f,1.0f,1.0f,GO});
		GO += 0.01;
		if (GO>= 1.0f) {
			GO = 1.0f;
		}
		break;
	}
	}
	if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Title>(0, "titel");
		DeleteGO(this);
	}
}