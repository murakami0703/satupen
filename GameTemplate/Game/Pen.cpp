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
	CQuaternion qRot = player->Getm_Rotation();
	m_position = pos;
	m_position.y = pos.y + 30.0f;
	m_rotation = qRot;
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_scale = { 1.0f,1.0f,1.0f };
	m_skinModelRender->SetScale(m_scale);

	m_charaCon.Init(
		3.0f,  //半径。
		0.5f,  //高さ。
		m_position //初期座標。
	);

	return true;
}

void Pen::Update()
{
	//飛ばすよお
	if (keisannflag == false) {

		Scope* scope = FindGO<Scope>("scope");
		CVector3 s_pos = scope->Getm_Position();
		//カーソルの座標をスクリーン座標系から正規化座標系に変換する。
		CVector3 worldPos;
		MainCamera().CalcWorldPositionFromScrenPosition(worldPos, { s_pos.x, s_pos.y }, 0.95f);
		CVector3 vBase = { 0.0f,0.0f,1.0f };
		m_rotation.Apply(vBase);
		P_target = worldPos;
		
		diff = P_target - m_position;
		diff.Normalize();
		keisannflag = true;
	}
	CQuaternion qRot;
	qRot.SetRotation({ 0.0, 0.0f, 1.0f }, diff);
	m_position = m_charaCon.Execute(diff * moveSpeed, (1.0 / 60.0f));
	m_skinModelRender->SetRotation(qRot);
	//座標を伝える。
	m_skinModelRender->SetPosition(m_position);
	m_timer++;
	
	//もし壁に当たってたら消える
	if (m_charaCon.IsOnWall() == true) {
		DeleteGO(this);

	}
	//時間がたつと消えるよ
	if (m_timer == pendelete) {
		DeleteGO(this);
	}
	//敵に当たると自分も消えるよ
	if (dathflag == true) {	
		DeleteGO(this);
	}
}

