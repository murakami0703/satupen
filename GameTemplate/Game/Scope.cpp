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
	m_position.x = m_position.x + R_stick.x * 30.0f;
	m_position.y = m_position.y + R_stick.y * 30.0f;
	//RB3‚ð‰Ÿ‚·‚Æ^‚ñ’†‚É–ß‚Á‚Ä‚­‚é‚æB
	if (Pad(0).IsTrigger(enButtonRB3)) {		
			m_position.x = 0.0f;
			m_position.y = 0.0f;
	}

	if (m_position.y > 120.0f) {
		m_position.y = 120.0f;
	}
	if (m_position.y < -150.0f) {
		m_position.y = -150.0f;
	}
	if (m_position.x > 580.0f) {
		m_position.x = 580.0f;
	}
	if (m_position.x < -580.0f) {
		m_position.x = -580.0f;
	}



	m_sprite->SetPosition(m_position);
}
