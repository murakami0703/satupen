#include "stdafx.h"
#include "GameData.h"

GameData* GameData::m_instance = nullptr;

GameData::GameData()
{
	if (m_instance != nullptr) {
		std::abort(); //���łɏo�Ă��邽�߃N���b�V��
	}

	//���̃C���X�^���X��B��̃C���X�^���X�Ƃ��ċL�^����
	m_instance = this;

}

GameData::~GameData()
{
	//�C���X�^���X���j�����ꂽ�̂ŁAnullptr����
	m_instance = nullptr;

}