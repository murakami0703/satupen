#include "stdafx.h"
#include "OPsound.h"

OPsound* OPsound::m_instance = nullptr;

OPsound::OPsound()
{
	if (m_instance != nullptr) {
		std::abort(); //���łɏo�Ă��邽�߃N���b�V��
	}

	//���̃C���X�^���X��B��̃C���X�^���X�Ƃ��ċL�^����
	m_instance = this;
}


OPsound::~OPsound()
{
	//�C���X�^���X���j�����ꂽ�̂ŁAnullptr����
	m_instance = nullptr;
	DeleteGO(m_sound);
}
bool OPsound::Start()
{
	//�T�E���h
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/game_maoudamashii_8_orgel09.wav");
	m_sound->Play(true);
	m_sound->SetVolume(0.5f);
	return true;
}


