#include "stdafx.h"
#include "EnemyChildren.h"

EnemyChildren::EnemyChildren()
{

}
EnemyChildren::~EnemyChildren()
{

}
bool EnemyChildren::Start()
{
	return true;
}
void EnemyChildren::Childrenidle()
{
	//‘Ò‹@ó‘Ô
}
void EnemyChildren::ChildrenWalk()
{
	//•à‚«ó‘Ô
}
void EnemyChildren::ChildrenRunaway()
{
	//“¦‚°‚Ä‚éó‘Ô
}


void EnemyChildren::Update()
{
	switch (m_state)
	{
	case EnemyChildren::EnState_idle:
		break;
	case EnemyChildren::EnState_walk:
		break;
	case EnemyChildren::EnState_runaway:
		break;
	}
}
