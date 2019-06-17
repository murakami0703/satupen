#include "stdafx.h"
#include "Status.h"


Status::Status()
{
}


Status::~Status()
{
	DeleteGO(m_sprite);
}
bool Status::Start()
{
	//スプライドを初期化
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/midriwaku1.dds", 1280, 720);
	m_sprite1 = NewGO<prefab::CSpriteRender>(0);
	m_sprite1->Init(L"sprite/taim.dds", 1280, 720);
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/wakuwaku.dds", 1280, 720);
	m_sprite3 = NewGO<prefab::CSpriteRender>(0);
	m_sprite3->Init(L"sprite/pen.dds", 1280, 720);
	m_sprite4 = NewGO<prefab::CSpriteRender>(0);
	m_sprite4->Init(L"sprite/waku4.dds", 1280, 720);
	m_sprite5 = NewGO<prefab::CSpriteRender>(0);
	m_sprite5->Init(L"sprite/kao .dds", 1280, 720);

	return true;

}
void Status::Update()
{
	
}
