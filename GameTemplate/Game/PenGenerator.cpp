#include "stdafx.h"
#include "Pen.h"
#include "PenGenerator.h"
#include "GameData.h"
#include "Player.h"

PenGenerator* PenGenerator::m_instance = nullptr;

PenGenerator::PenGenerator()
{
	if (m_instance != nullptr) {
		std::abort(); //���łɏo�Ă��邽�߃N���b�V��
	}

	//���̃C���X�^���X��B��̃C���X�^���X�Ƃ��ċL�^����
	m_instance = this;
}


PenGenerator::~PenGenerator()
{
	//�C���X�^���X���j�����ꂽ�̂ŁAnullptr����
	m_instance = nullptr;
}

bool PenGenerator::Start()
{

	return true;
}
void PenGenerator::Update()
{
	Player* pl = FindGO<Player>("player");
	GameData* gamedata = GameData::GetInstance();
	int Zandan = gamedata->GetZandan();

	if (Zandan > 0) {
		//�c�e����B
		if(pl->IsSetup() == true)
			//�\���Ă�B
		if (Pad(0).IsTrigger(enButtonRB1)) {
			//����
			m_isFire = true;
			NewGO<Pen>(0, "pen");
			gamedata->Zandannkasan(-1);
		}
		else {
			m_isFire = false;

		}
	}
	else if (Zandan <= 0) {
		//���Ă܂���I�I�I�I�I�W�߂āI�I�I�I�e�L�X�g�\��
	}
	
}

