#include "stdafx.h"
#include "EnemyMan.h"

EnemyMan::EnemyMan()
{

}
EnemyMan::~EnemyMan()
{

}

bool EnemyMan::Start()
{
	return true;
}
void EnemyMan::Manidle()
{
	//待機状態
}
void EnemyMan::ManWalk()
{
	//歩き状態
}
void EnemyMan::ManAttack()
{
	//攻撃状態
}

void EnemyMan::Update()
{
	switch (m_state)
	{
	case EnemyMan::EnState_idle:
		break;
	case EnemyMan::EnState_walk:
		break;
	case EnemyMan::EnState_attack:
		break;
	}
}
