#include "stdafx.h"
#include "Scope.h"
#include "Player.h"

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
	m_sprite->Init(L"sprite/suko.dds", 150.0f, 150.0f);
	return true;
}
void Scope::Update()
{
	Player* player = Player::GetInstance();

	//プレイヤーがLBを押したときだけ動かします
	if (player->IsSetup() == true) {
		R_stick.x = Pad(0).GetRStickXF();
		R_stick.y = Pad(0).GetRStickYF();
		R_stick.z = 0.0f;
		m_position.x = m_position.x + R_stick.x * 30.0f;
		m_position.y = m_position.y + R_stick.y * 30.0f;
		m_sprite->SetMulColor({ 1.0f,1.0f,1.0f,0.4f });
	}
	else {		//離したら中央に戻ってくる。
		m_position.x = 0.0f;
		m_position.y = 0.0f;
		m_sprite->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });

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
