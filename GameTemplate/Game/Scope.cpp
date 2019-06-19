#include "stdafx.h"
#include "Scope.h"

Scope::Scope()
{
}


Scope::~Scope()
{
	DeleteGO(m_sprite);
}

bool Scope::Start()
{
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/suko.dds", 200, 200);
	return true;
}
void Scope::Update()
{
	R_stick.x = Pad(0).GetRStickXF();
	R_stick.y = Pad(0).GetRStickYF();
	R_stick.z = 0.0f;
	m_position.x = R_stick.x * 500.0f;
	m_position.y = R_stick.y * 100.0f;
	m_sprite->SetPosition(m_position);
}
