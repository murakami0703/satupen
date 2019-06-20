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
	//‘Ò‹@ó‘Ô
}
void EnemyWoman::WomanWalk()
{
	//•à‚«ó‘Ô
}
void EnemyWoman::WomanRunaway()
{
	//“¦‚°‚Ä‚éó‘Ô
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


