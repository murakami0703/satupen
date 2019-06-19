#include "stdafx.h"
#include "Pen.h"
#include "Scope.h"
#include "Player.h"

Pen::Pen()
{
}


Pen::~Pen()
{
	DeleteGO(m_skinModelRender);
}

bool Pen::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/ya.cmo");
	//プレイヤーの場所に発生
	Player* player = FindGO<Player>("player");
	CVector3 pos = player->Getm_Position();
	m_position = pos;
	m_skinModelRender->SetPosition(m_position);
	m_scale = { 2.0f,2.0f,2.0f };
	m_skinModelRender->SetScale(m_scale);

	return true;
}

void Pen::Update()
{
	//飛ばすよお
	if (keisannflag == false) {

		Player* player = FindGO<Player>("player");
		CVector3 p_pos = player->Getm_Position();
		Scope* scope = FindGO<Scope>("scope");
		CVector3 s_pos = scope->Getm_Position();
		s_pos.z = s_pos.y;
		//　向かせたい方向
		CVector3 enemyForward = { 1.0f, 0.0f, 0.0f };
		buvec = s_pos - p_pos;
		//　Y成分は除去して正規化する。Y成分を入れると空を向いたりするよ。
		buvec.y = 0.0f;
		buvec.Normalize();
		CQuaternion qRot;
		qRot.SetRotation(enemyForward, buvec);
		m_rotation = qRot;

		keisannflag = true;
	}
	m_position += buvec * moveSpeed;

	//座標を伝える。
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

	m_timer++;
	if (m_timer == pendelete) {
		//時間がたったらインスタンスを削除する。
		DeleteGO(this);
	}
}

