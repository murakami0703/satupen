#include "stdafx.h"
#include "EnemyWoman.h"

EnemyWoman::EnemyWoman() 
{

}
EnemyWoman::~EnemyWoman()
{

}

bool EnemyWoman::Start()
{
	return true;
}
void EnemyWoman::Womanidle()
{
	//待機状態
}
void EnemyWoman::WomanWalk()
{
	//歩き状態
}
void EnemyWoman::WomanRunaway()
{
	//逃げてる状態
}

void EnemyWoman::Update()
{
	switch (m_state)
	{
	case EnemyWoman::EnState_idle:
		break;
	case EnemyWoman::EnState_walk:
		break;
	case EnemyWoman::EnState_runaway:
		break;
	}
}


