#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "GameData.h"


Item::Item()
{

}
Item::~Item()
{

}
bool Item::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Item.cmo");
	m_position = { 300.0f,0.0f,200.0f };
	m_skinModelRender->SetPosition(m_position);
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
		//置かれてるよぉぉ
		if (diff.Length() < 100.0f) {
			//プレイヤーがアイテムに近いですねぇ
			m_state = Follow;
		}
		break;
	}
	case Item::Follow:
	{
		//超至近距離に向かうよ！
		CVector3 move = diff;
		move.Normalize();
		m_position += move * 6.0f;

		if (diff.Length() < 3.0f) {
			GameData* gamedata = GameData::GetInstance();
			gamedata->Zandannkasan(+3);
			DeleteGO(this);
		}
		break;
	}

	}
	m_skinModelRender->SetPosition(m_position);
}