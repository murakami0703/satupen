#include "stdafx.h"
#include "EnemyBird.h"
#include "Player.h"
#include "Pen.h"
#include "GameData.h"

EnemyBird::EnemyBird()
{

}
EnemyBird::~EnemyBird()
{
	DeleteGO(m_skinModelRender);

}

bool EnemyBird::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/karasu/karasuu.cmo");
	m_skinModelRender->SetPosition(m_position);

	//キャラコン
	m_charaCon.Init(
		15.0f,  //半径。
		25.0f,  //高さ。
		m_position //初期座標。
	);
	return true;
}
void EnemyBird::BirdIdle()
{
	//待機状態
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	stoptimer++;
	moveVec = moveVec * 0.0f;	//動きませーーん
	if (stoptimer >= stopendtimer) {
		m_state = EnState_walk;
	}
	if (diff.Length() < flyRange) {
		//距離が近いので飛びます
		m_state = EnState_fly;
	}

}
void EnemyBird::BirdWalk()
{
	//歩き状態
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	count++;

	if (count == randomCount) {
		//ランダムで方向を決定して動きます
		wrandom = rand() % 360;
		m_rotation.SetRotation(CVector3::AxisY, (float)wrandom);
		walkmove = { 0.0f, 0.0f,-1.0f };
		m_rotation.Multiply(walkmove);
		count = 0;
	}
	else if (diff.Length() < flyRange) {
		//距離が近いので飛びます！
		m_state = EnState_fly;
	}
	moveVec = walkmove * randomSpeed;
	m_position = m_charaCon.Execute(moveVec);
}
void EnemyBird::BirdFly()
{
	//飛び
}
void EnemyBird::BirdDeath()
{
	//死
	DeleteGO(this);
}

void EnemyBird::Update()
{
	switch (m_state)
	{
	case EnemyBird::EnState_idle:
		BirdIdle();
		break;
	case EnemyBird::EnState_walk:
		BirdWalk();
		break;
	case EnemyBird::EnState_fly:
		BirdFly();
		break;
	case EnemyBird::EnState_death:
		BirdDeath();
		break;

	}

	//ペンとの衝突判定
	QueryGOs<Pen>("pen", [&](Pen* pen) {
		CVector3 pen_position = pen->Getm_Position();
		CVector3 diff = pen_position - m_position;
		if (diff.Length() < 30.0f) {
			//撃たれた....
			GameData* gamedata = GameData::GetInstance();
			gamedata->DeadHkasan(1);
			//ペンも消滅
			pen->SetDeath();
			m_state = EnState_death;//死にます。
		}
		return true;
		});

	//移動と回転
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);


}

