#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
}


Title::~Title()
{
}

bool Title::Start()
{
	return true;
}
void Title::New()
{
	//新しくゲームを始める

}
void Title::Load()
{
	//続きから

}
void Title::Exit()
{
	//終了（消えるよ！）

}

void Title::Update()
{
	//選択処理
	switch (m_state)
	{
	case Estate_New:
		New();
		break;
	case Estate_Load:
		Load();
		break;
	case Estate_Exit:
		Exit();
		break;
	}
	if (Pad(0).IsTrigger(enButtonA)) {
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}