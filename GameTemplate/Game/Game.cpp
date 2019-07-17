#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "GameData.h"
#include "Player.h"
#include "Status.h"
#include "PenGenerator.h"
#include "Scope.h"
#include "Level.h"
#include "EffectManager.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}


Game::~Game()
{
	DeleteGOs("gcamera");
	DeleteGOs("player");
	DeleteGOs("gamedata");
	DeleteGOs("scope");
	DeleteGOs("status");
	DeleteGOs("penG");
	DeleteGOs("level");
	DeleteGOs("EffectManager");
	DeleteGOs("light");
	DeleteGO("空");
}
bool Game::Start()
{
	NewGO<Player>(0, "player");
	NewGO<GameCamera>(0, "gcamera");
	NewGO<Scope>(0, "scope");
	NewGO<Status>(0, "status");
	NewGO<GameData>(0, "gamedata");
	NewGO<PenGenerator>(0, "penG");
	NewGO<Level>(0, "level");
	NewGO<EffectManager>(0, "EffectManager");

	//1本目
	auto dirLig = NewGO<prefab::CDirectionLight>(0, "light");
	dirLig->SetColor({5.0f, 5.0f, 5.0f, 1.0f});
	CVector3 dir = { 1.0f, -1.0f, 1.0f };
	dir.Normalize();
	dirLig->SetDirection(dir);
	//2本目
	dirLig = NewGO<prefab::CDirectionLight>(0, "light");
	dirLig->SetColor({ 2.0f, 2.0f, 2.0f, 1.0f });
	dir = { -1.0f, -1.0f, -1.0f };
	dir.Normalize();
	dirLig->SetDirection(dir);

	//3本目
	dirLig = NewGO<prefab::CDirectionLight>(0, "light");
	dirLig->SetColor({ 2.0f, 2.0f, 2.0f, 1.0f });
	dir = { 1.0f, -1.0f, 1.0f };
	dir.Normalize();
	dirLig->SetDirection(dir);

	//空
	auto sky = NewGO<prefab::CSky>(0, "空");
	sky->SetScale({ 8000.0f, 8000.0f, 8000.0f });
	CVector3 lightDir = { -1.0f, -1.0f, 1.0f };
	lightDir.Normalize();
	GraphicsEngine().GetDirectionShadowMap().SetLightDirection(lightDir);
	return true;
}

void Game::Update()
{	
	GameData* game = GameData::GetInstance();
	float plHp = game->Get_Life();
	//げむオーバ
	if (plHp <= 0) {
		DeleteGO(this);
	}

}