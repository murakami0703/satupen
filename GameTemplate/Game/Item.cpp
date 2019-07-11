#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "GameData.h"


Item::Item()
{

}
Item::~Item()
{
	DeleteGO(m_skinModelRender);
}
bool Item::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Item.cmo");
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

	return true;
}
void Item::Update()
{
	Player* player = Player::GetInstance();
	CVector3 p_pos = player->Getm_Position();
	CVector3 diff = p_pos - m_position;
	switch (m_state) {
	case Item::Wait: 
	{
		//�u����Ă�悧��
		if (diff.Length() < 100.0f) {
			//�v���C���[���A�C�e���i�e�j�ɋ߂��ł��˂�
			m_state = Follow;
		}
		break;
	}
	case Item::Follow:
	{
		//�v���C���[�̒����ߋ����Ɉړ������I�I
		CVector3 move = diff;
		move.Normalize();
		m_position += move * 6.0f;
		//�������
		if (diff.Length() < 3.0f) {
			GameData* gamedata = GameData::GetInstance();
			gamedata->Zandannkasan(+3);
			DeleteGO(this);
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/MZaitemu.wav");
			m_sound->Play(false);
			m_sound->SetVolume(0.3f);
		}
		break;
	}

	}
	m_skinModelRender->SetPosition(m_position);
}