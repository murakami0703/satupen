#include "stdafx.h"
#include "EnemyDog.h"
#include "Player.h"
#include "Pen.h"
#include "GameData.h"


EnemyDog::EnemyDog()
{

}
EnemyDog::~EnemyDog()
{
	DeleteGO(m_skinModelRender);
}

bool EnemyDog::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/inu/inuu.cmo");
	m_skinModelRender->SetPosition(m_position);

	//キャラコン
	m_charaCon.Init(
		15.0f,  //半径。
		25.0f,  //高さ。
		m_position //初期座標。
	);
	return true;
}
void EnemyDog::DogIdle()
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
	if (diff.Length() < attackRange) {
		//距離が近いので逃げます！
		m_state = EnState_attack;
	}
}
void EnemyDog::DogWalk()
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
	else if (diff.Length() < attackRange) {
		//距離が近いので攻撃しま！
		m_state = EnState_attack;
	}
	moveVec = walkmove * randomSpeed;
	m_position = m_charaCon.Execute(moveVec);
}
void EnemyDog::DogAttack()
{
	//攻撃状態
	Player* player = Player::GetInstance();
	CVector3 P_Position = player->Getm_Position();
	CVector3 diff = P_Position - m_position;

	if (diff.Length() < 600.0f) {
		//近づきます
		diff.y = 0.0f;
		diff.Normalize();
		moveVec = diff * attackSpeed;
	}
	else if (diff.Length() < 20.0f) {
		//アニメーション流して攻撃しや
	}
	else {
		//離れたのでその場で移動しま
		m_state = EnState_walk;
	}

	//回転の処理
	if (fabsf(m_position.x) < 0.001f
		&& fabsf(m_position.z) < 0.001f) {
		//わからん
		return;
	}


	CVector3 enemyForward = { 0.0f, 0.0f, 1.0f };

	//　向かせたい方向のベクトルを計算する。
	CVector3 targetVector = P_Position - m_position;
	//　Y成分は除去して正規化する。Y成分を入れると空を向いたりするよ。
	targetVector.y = 0.0f;
	targetVector.Normalize();
	CQuaternion qRot;
	qRot.SetRotation(enemyForward, targetVector);
	m_rotation = qRot;
	m_position = m_charaCon.Execute(moveVec);


}
void EnemyDog::DogDeath()
{
	//死
	DeleteGO(this);
}

void EnemyDog::Update()
{
	switch (m_state)
	{
	case EnemyDog::EnState_idle:
		DogIdle();
		break;
	case EnemyDog::EnState_walk:
		DogWalk();
		break;
	case EnemyDog::EnState_attack:
		DogAttack();
		break;
	case EnemyDog::EnState_death:
		DogDeath();
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
