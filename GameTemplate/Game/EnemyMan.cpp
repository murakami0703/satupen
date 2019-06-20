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
	//‘Ò‹@ó‘Ô
}
void EnemyMan::ManWalk()
{
	//•à‚«ó‘Ô
}
void EnemyMan::ManAttack()
{
	//UŒ‚ó‘Ô
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
