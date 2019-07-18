#include "stdafx.h"
#include "Status.h"
#include"GameData.h"
#include"Player.h"
#include "Result.h"
#include "Game.h"
#include "Result.h"
#include"TimeUP.h"

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
	DeleteGO(m_sprite8);
	DeleteGO(m_sprite9);
	DeleteGO(m_sprite10);
	DeleteGO(m_sprite12);
	DeleteGO(m_sprite13);
	DeleteGO(m_sprite14);
	DeleteGO(m_sprite15);
	DeleteGO(m_sprite16);
	DeleteGO(m_sprite17);
	DeleteGO(m_sprite18);
	DeleteGO(m_sprite20);

	DeleteGO(m_font);
	DeleteGO(m_fontP);
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
	//時計の針
	m_sprite20 = NewGO<prefab::CSpriteRender>(0);
	m_sprite20->Init(L"sprite/hari.dds", 200.0f, 200.0f);
	m_position = { -10.0f,240.0f,0.0f };
	m_sprite20->SetPosition(m_position);//座標を反映
	//顔、ペンのBar
	m_sprite2 = NewGO<prefab::CSpriteRender>(0);
	m_sprite2->Init(L"sprite/wakuwaku.dds", 1280.0f, 720.0f);
	//ペンのスプライト
	m_sprite3 = NewGO<prefab::CSpriteRender>(0);
	m_sprite3->Init(L"sprite/pen.dds", 1280.0f, 720.0f);
	m_position = { -250.0f,49.0f,0.0f };//座標
	m_sprite3->SetPosition(m_position);//座標を反映
	m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	//ペンのスプライト２
	m_sprite12 = NewGO<prefab::CSpriteRender>(0);
	m_sprite12->Init(L"sprite/pen2.dds", 1280.0f, 720.0f);
	m_position = { -190.0f,49.0f,0.0f };//座標
	m_sprite12->SetPosition(m_position);//座標を反映
	m_sprite12->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤。翠、青
	//ペンのスプライト３
	m_sprite13 = NewGO<prefab::CSpriteRender>(0);
	m_sprite13->Init(L"sprite/pen3.dds", 1280.0f, 720.0f);
	m_position = { -130.0f,49.0f,0.0f };//座標
	m_sprite13->SetPosition(m_position);//座標を反映
	m_sprite13->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	//ペンのスプライト４
	m_sprite14 = NewGO<prefab::CSpriteRender>(0);
	m_sprite14->Init(L"sprite/pen4.dds", 1280.0f, 720.0f);
	m_position = { -70.0f,49.0f,0.0f };//座標
	m_sprite14->SetPosition(m_position);//座標を反映
	m_sprite14->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	//ペンのスプライト５
	m_sprite15 = NewGO<prefab::CSpriteRender>(0);
	m_sprite15->Init(L"sprite/pen5.dds", 1280.0f, 720.0f);
	m_position = { -10.0f,49.0f,0.0f };//座標
	m_sprite15->SetPosition(m_position);//座標を反映
	m_sprite15->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、みどり、青
	//ペンのスプライト６
	m_sprite16 = NewGO<prefab::CSpriteRender>(0);
	m_sprite16->Init(L"sprite/pen6.dds", 1280.0f, 720.0f);
	m_position = { 50.0f,49.0f,0.0f };//座標
	m_sprite16->SetPosition(m_position);//座標を反映
	m_sprite16->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB
	//HPBarわく
	m_sprite4 = NewGO<prefab::CSpriteRender>(3);
	m_sprite4->Init(L"sprite/waku4.dds", 540.0f, 150.0f);
	m_sprite4->SetPosition({ 130.0f,225.0f,0.0f });
	//HpWbar白
	m_sprite7 = NewGO<prefab::CSpriteRender>(1);
	m_sprite7->Init(L"sprite/HPWbar.dds", 540.0f, 165.0f);
	m_sprite7->SetPosition({ 130.0f,225.0f,0.0f });
	//HPBbar翠
	m_sprite18 = NewGO<prefab::CSpriteRender>(2);
	m_sprite18->Init(L"sprite/HPbar.dds", 540.0f, 165.0f);
	m_sprite18->SetPosition({ 123.0f,225.0f,0.0f });
	//HPbar黒
	m_sprite17 = NewGO<prefab::CSpriteRender>(0);
	m_sprite17->Init(L"sprite/HPBbar.dds", 540.0f, 165.0f);
	m_sprite17->SetPosition({ 123.0f,225.0f,0.0f });
	//顔のスプライト１
	m_sprite5 = NewGO<prefab::CSpriteRender>(0);
	m_sprite5->Init(L"sprite/kao .dds", 1280.0f, 720.0f);
	m_position = { -200.0f, 151.5f, 0.0f };//座標
	m_sprite5->SetPosition(m_position);//座標を反映
	m_sprite5->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	//顔のスプライト２
	m_sprite6 = NewGO<prefab::CSpriteRender>(0);
	m_sprite6->Init(L"sprite/kao2.dds", 1280.0f, 720.0f);
	m_position = { -130.0f, 151.5f, 0.0f };//座標
	m_sprite6->SetPosition(m_position);//座標を反映
	m_sprite6->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、翠、青
	//顔のスプライト３
	m_sprite8 = NewGO<prefab::CSpriteRender>(0);
	m_sprite8->Init(L"sprite/kao3.dds", 1280.0f, 720.0f);
	m_position = { -60.0f,151.5f,0.0f };//座標
	m_sprite8->SetPosition(m_position);//座標は反映/
	m_sprite8->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	//顔のスプライト４
	m_sprite9 = NewGO<prefab::CSpriteRender>(0);
	m_sprite9->Init(L"sprite/kao4.dds", 1280.0f, 720.0f, 0.0f);
	m_position = { 10.0f,151.5f,0.0f };//座標
	m_sprite9->SetPosition(m_position);
	m_sprite9->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	//顔のスプライト5
	m_sprite10 = NewGO<prefab::CSpriteRender>(0);
	m_sprite10->Init(L"sprite/kao5.dds", 1280.0f, 720.0f, 0.0f);
	m_position = { 80.0f,151.5f,0.0f };//座標
	m_sprite10->SetPosition(m_position);
	m_sprite10->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青

	//フォント
	m_font = NewGO<prefab::CFontRender>(0);
	m_fontP = NewGO<prefab::CFontRender>(0);

	return true;

}
void Status::Update()
{
	//HP
	CVector3 LifeScale = CVector3::Zero;
	Player* player = FindGO<Player>("player");
	GameData* gamedata = GameData::GetInstance();
	//寿命ゲージを動かす
	float DEF_Life = (float)gamedata->GetDEF_Life();
	float NOW_Life = (float)gamedata->Get_Life();

	//寿命のを計算
	float LifeY = NOW_Life / DEF_Life;
	//???
	LifeScale = { LifeY,1.0f,1.0f };
	//寿命バーの色が変わる基準
	float RED_Life = DEF_Life / 2.0f;
	//寿命バーの色変え
	if (NOW_Life < RED_Life) {
		LifeColor = { 1.0f,0.0f,0.0f,1.0f };
	}
	else {
		LifeColor = { 0.0f,1.0f,0.0f,1.0f };
	}
	m_sprite4->SetPivot(LifePivot);
	m_sprite7->SetPivot(LifePivot);
	m_sprite18->SetPivot(LifePivot);//4,7,17
	m_sprite17->SetPivot(LifePivot);
	m_sprite18->SetScale(LifeScale);
	m_sprite18->SetMulColor(LifeColor);
	//時計針回すやつ　時間は鬼調整で
	rag += -0.06f * GameTime().GetFrameDeltaTime();
	CQuaternion rot;
	rot.SetRotation(CVector3::AxisZ, -0.06f * GameTime().GetFrameDeltaTime());
	m_rotation.Multiply(rot);
	m_sprite20->SetRotation(m_rotation);
	if (CMath::DegToRad(359.0f) < -rag) {
		NewGO<TimeUP>(0);
		DeleteGO(this);
	}
	//何人殺したかのやつ
	wchar_t text[256];
	int GetDH = gamedata->GetDeadH();
	if (GetDH > 5) {
		int TDH = GetDH - 5;
		swprintf(text, L"\n+%02d", TDH);
		m_font->SetText(text);
		m_font->SetPosition({ -230.0f, 340.0f });
		m_font->SetPivot({ 0.0f, 0.0f });///右下
	}
	//ペンをだす
	wchar_t text2[256];
	int GetZan = gamedata->GetZandan();
	if (GetZan > 5) {
		swprintf(text2, L"\n+%02d", GetZan);
		m_fontP->SetText(text2);
		m_fontP->SetPosition({ -230.0f, 275.0f });
		m_fontP->SetPivot({ 0.0f, 0.0f });///右下

	}
	else {
		swprintf(text2, L"");
		m_fontP->SetText(text2);

	}
	//顔の出すやつ
	//5個だけテクスチャやで
	if (gamedata->GetDeadH() >= 1) {
		m_sprite5->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite5->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	}
	if (gamedata->GetDeadH() >= 2) {
		m_sprite6->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、翠、青
	}
	else {
		m_sprite6->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、翠、青
	}
	if (gamedata->GetDeadH() >= 3) {
		m_sprite8->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite8->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	}
	if (gamedata->GetDeadH() >= 4) {
		m_sprite9->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite9->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	}
	if (gamedata->GetDeadH() >= 5) {
		m_sprite10->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite10->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });//RGB赤、緑、青
	}


	//こっちペン3.12.13.14.15.16.19
	//6個だけテクスチャやで
	if (gamedata->GetZandan() >= 1) {
		m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite3->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	}
	if (gamedata->GetZandan() >= 2) {
		m_sprite12->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite12->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	}
	if (gamedata->GetZandan() >= 3) {
		m_sprite13->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite13->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	}
	if (gamedata->GetZandan() >= 4) {
		m_sprite14->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite14->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	}
	if (gamedata->GetZandan() >= 5) {
		m_sprite15->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite15->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	}
	if (gamedata->GetZandan() >= 6) {
		m_sprite16->SetMulColor({ 1.0f,1.0f,1.0f,1.0f });//RGB赤、緑、青
	}
	else {
		m_sprite16->SetMulColor({ 1.0f,1.0f,1.0f,0.0f });
	}
}
