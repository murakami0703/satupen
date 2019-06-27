#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
}


Title::~Title()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite1);
	DeleteGO(m_sprite2);
	DeleteGO(m_sprite3);
	DeleteGO(m_sprite4);
	DeleteGO(m_sprite5);
	DeleteGO(m_sprite6);
}

bool Title::Start()
{
	//スプライト初期化
	//スプライト　赤いバック
	m_sprite= NewGO<prefab::CSpriteRender>(1);
	m_sprite->Init(L"sprite/Titel/saturikuBG.dds", 1280.0f, 720.0f);
	//スプライト　さつりくのペン
	m_sprite1 = NewGO<prefab::CSpriteRender>(4);
	m_sprite1->Init(L"sprite/Titel/saturikupen.dds", 500.0f, 150.0f);
	m_position = { 0.0f,-30.0f,0.0f };
	m_sprite1->SetPosition(m_position);
	//スプライト　殺戮の剣
	m_sprite2 = NewGO<prefab::CSpriteRender>(3);
	m_sprite2->Init(L"sprite/Titel/saturiku.dds", 970.0f, 410.0f);
	m_position = { 0.0f,120.0f,0.0f };
	m_sprite2->SetPosition(m_position);
	//スプライト　殺戮のぺん白
	m_sprite3 = NewGO<prefab::CSpriteRender>(2);
	m_sprite3->Init(L"sprite/Titel/saturikunopen.dds", 300.0f, 300.0f);
	m_position = { 300.0f,150.0f,0.0f };
	m_sprite3->SetPosition(m_position);
	//スプライト　血
	m_sprite4 = NewGO<prefab::CSpriteRender>(5);
	m_sprite4->Init(L"sprite/Titel/ti.dds", 1280.0f, 720.0f);
	//スプライト　殺戮を始める
	m_sprite5 = NewGO<prefab::CSpriteRender>(6);
	m_sprite5->Init(L"sprite/Titel/hazimeru.dds", 350.0f, 100.0f);
	m_position = { 300.0f,-200.0f,0.0f };
	m_sprite5->SetPosition(m_position);
	//スプライト　懺悔する
	m_sprite6 = NewGO<prefab::CSpriteRender>(7);
	m_sprite6->Init(L"sprite/Titel/zange.dds", 300.0f, 100.0f);
	m_position = { 300.0f,-280.0f,0.0f };
	m_sprite6->SetPosition(m_position);

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
	case Title::Estate_New:
		New();
		break;
	case Estate_Load:
		Load();
		break;
	case Estate_Exit:
		Exit();
		break;
	}
	if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}

}