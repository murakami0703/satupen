#include "stdafx.h"
#include "Status.h"
#include"GameData.h"
#include"Player.h"


Status::Status()
{

}


Status::~Status()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite1);
	DeleteGO(m_sprite2);
	DeleteGO(m_sprite3);
	DeleteGO(m_sprite4);
	DeleteGO(m_sprite5);
	DeleteGO(m_sprite6);
	DeleteGO(m_sprite7);
}
bool Status::Start()
{
	//スプライドを初期化
	//全体のBarのスプライト
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/midriwaku1.dds", 1280.0f, 720.0f);
	//時計スプライト
	m_sprite1 = NewGO<prefab::CSpriteRender>(0);
	m_sprite1->Init(L"sprite/taim.dds", 1280.0f, 720.0f);
	//顔、ペンのBar
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/wakuwaku.dds", 1280.0f, 720.0f);
	//ペンのスプライト
	m_sprite3 = NewGO<prefab::CSpriteRender>(0);
	m_sprite3->Init(L"sprite/pen.dds", 1280.0f, 720.0f);
	m_position = { -250.0f,49.0f,0.0f };//座標
	m_sprite3->SetPosition(m_position);//座標を反映
	//ペンのスプライト２
	m_sprite12 = NewGO<prefab::CSpriteRender>(0);
	m_sprite12->Init(L"sprite/pen2.dds", 1280.0f, 720.0f);
	m_position = { -190.0f,49.0f,0.0f };//座標
	m_sprite12->SetPosition(m_position);//座標を反映
	//ペンのスプライト３
	m_sprite13 = NewGO<prefab::CSpriteRender>(0);
	m_sprite13->Init(L"sprite/pen3.dds", 1280.0f, 720.0f);
	m_position = { -130.0f,49.0f,0.0f };//座標
	m_sprite13->SetPosition(m_position);//座標を反映
	//ペンのスプライト４
	m_sprite14 = NewGO<prefab::CSpriteRender>(0);
	m_sprite14->Init(L"sprite/pen4.dds", 1280.0f, 720.0f);
	m_position = { -70.0f,49.0f,0.0f };//座標
	m_sprite14->SetPosition(m_position);//座標を反映
	//ペンのスプライト５
	m_sprite15 = NewGO<prefab::CSpriteRender>(0);
	m_sprite15->Init(L"sprite/pen5.dds", 1280.0f, 720.0f);
	m_position = { -10.0f,49.0f,0.0f };//座標
	m_sprite15->SetPosition(m_position);//座標を反映
	//ペンのスプライト６
	m_sprite16 = NewGO<prefab::CSpriteRender>(0);
	m_sprite16->Init(L"sprite/pen6.dds", 1280.0f, 720.0f);
	m_position = { 50.0f,49.0f,0.0f };//座標
	m_sprite16->SetPosition(m_position);//座標を反映
	//HPBarわく
	m_sprite4 = NewGO<prefab::CSpriteRender>(0);
	m_sprite4->Init(L"sprite/waku4.dds", 1280.0f, 720.0f);
	//HpWbar白
	m_sprite7 = NewGO<prefab::CSpriteRender>(0);
	m_sprite7->Init(L"sprite/HPWbar.dds", 1280.0f, 720.0f);
	//HPBbar翠
	m_sprite18 = NewGO<prefab::CSpriteRender>(0);
	m_sprite18->Init(L"sprite/HPbar.dds", 1280.0f, 720.0f);
	//HPbar黒
	m_sprite17 = NewGO<prefab::CSpriteRender>(0);
	m_sprite17->Init(L"sprite/HPBbar.dds", 1280.0f, 720.0f);
	//顔のスプライト１
	m_sprite5 = NewGO<prefab::CSpriteRender>(0);
	m_sprite5->Init(L"sprite/kao .dds", 1280.0f, 720.0f);
	m_position= { -200.0f, 151.5f, 0.0f };//座標
	m_sprite5->SetPosition(m_position);//座標を反映
	//顔のスプライト２
	m_sprite6 = NewGO<prefab::CSpriteRender>(0);
	m_sprite6->Init(L"sprite/kao2.dds", 1280.0f, 720.0f);
	m_position = { -130.0f, 151.5f, 0.0f };//座標
	m_sprite6->SetPosition(m_position);//座標を反映
	//顔のスプライト３
	m_sprite8 = NewGO<prefab::CSpriteRender>(0);
	m_sprite8->Init(L"sprite/kao3.dds", 1280.0f, 720.0f);
	m_position = { -60.0f,151.5f,0.0f };//座標
	m_sprite8->SetPosition(m_position);//座標は反映/
	//顔のスプライト４
	m_sprite9 = NewGO<prefab::CSpriteRender>(0);
	m_sprite9->Init(L"sprite/kao4.dds", 1280.0f, 720.0f, 0.0f);
	m_position = { 10.0f,151.5f,0.0f };//座標
	m_sprite9->SetPosition(m_position);
	//顔のスプライト5
	m_sprite10 = NewGO<prefab::CSpriteRender>(0);
	m_sprite10->Init(L"sprite/kao5.dds", 1280.0f, 720.0f, 0.0f);
	m_position = { 80.0f,151.5f,0.0f };//座標
	m_sprite10->SetPosition(m_position);
	//顔のスプライト6
	m_sprite11 = NewGO<prefab::CSpriteRender>(0);
	m_sprite11->Init(L"sprite/kao6.dds", 1280.0f, 720.0f, 0.0f);
	m_position = { 150.0f,151.5f,0.0f };//座標
	m_sprite11->SetPosition(m_position);
	return true;

}
void Status::Update()
{
    //HP
	CVector3 LifeScale = CVector3::Zero;
	Player* player = FindGO<Player>();
	Player * player = Player::GetInstance();
	GameData * gamedata = GameData::GetInstance();
	//寿命ゲージを動かす
	float DEF_Life = (float)gamedata->GetDEF_Life();
	float NOW_Life = (float)player->Life();

	//寿命のを計算
	float LifeY = NOW_Life / DEF_Life;

	//寿命バーの色が変わる基準
	float RED_Life = DEF_Life / 2.0f;
	//寿命バーの色変え
	if()
}
