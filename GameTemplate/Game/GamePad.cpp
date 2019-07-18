#include "stdafx.h"
#include "GamePad.h"
#include"Game.h"


GamePad::GamePad()
{
}


GamePad::~GamePad()
{
	DeleteGO(m_sprite);
}
bool GamePad::Start()
{
	m_sprite = NewGO < prefab::CSpriteRender >(0);
	m_sprite->Init(L"sprite/Titel/sousa.dds",1280.0f,720.0f);

	return true;
}
void GamePad::Update()
{
	if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}