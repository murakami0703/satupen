#include "stdafx.h"
#include "Pen.h"
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
	m_skinModelRender->SetPosition(m_position);

	return true;
}
void Pen::Follow()
{
	//プレイヤーに付いていくペン
	Player* player = FindGO<Player>("player");
	CVector3 pos = player->Getm_Position();

	if (Pad(0).IsTrigger(enButtonB)) {
		//Aボタンが押されたら飛ぶよ
		m_state = Estate_Attack;
	}
}
void Pen::Attack()
{
	//攻撃ﾀﾞﾖ
	/*if (keisannflag == false) {

		Player* player = FindGO<Player>("player");
		CVector3 pos = player->Getm_Position();
		buvec = diff;
		buvec.Normalize();

		//　向かせたい方向
		CVector3 enemyForward = { 1.0f, 0.0f, 0.0f };
		CVector3 targetVector = tes_Position - pos;
		//　Y成分は除去して正規化する。Y成分を入れると空を向いたりするよ。
		targetVector.y = 0.0f;
		targetVector.Normalize();
		CQuaternion qRot;
		qRot.SetRotation(enemyForward, targetVector);
		m_rotation = qRot;

		keisannflag = true;
	}*/
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

void Pen::Update()
{
	switch (m_state)
	{
	case Pen::Estate_Follow:
		Follow();
		break;
	case Pen::Estate_Attack:
		Attack();
		break;
	}
}

