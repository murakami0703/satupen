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
	//待機状態
}
void EnemyChildren::ChildrenWalk()
{
	//歩き状態
}
void EnemyChildren::ChildrenRunaway()
{
	//逃げてる状態
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
