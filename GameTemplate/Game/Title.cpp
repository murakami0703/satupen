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
	//�V�����Q�[�����n�߂�

}
void Title::Load()
{
	//��������

}
void Title::Exit()
{
	//�I���i�������I�j

}

void Title::Update()
{
	//�I������
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