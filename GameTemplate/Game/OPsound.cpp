#include "stdafx.h"
#include "OPsound.h"

OPsound* OPsound::m_instance = nullptr;

OPsound::OPsound()
{
	if (m_instance != nullptr) {
		std::abort(); //すでに出ているためクラッシュ
	}

	//このインスタンスを唯一のインスタンスとして記録する
	m_instance = this;
}


OPsound::~OPsound()
{
	//インスタンスが破棄されたので、nullptrを代入
	m_instance = nullptr;
	DeleteGO(m_sound);
}
bool OPsound::Start()
{
	//サウンド
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/game_maoudamashii_8_orgel09.wav");
	m_sound->Play(true);
	m_sound->SetVolume(0.5f);
	return true;
}


