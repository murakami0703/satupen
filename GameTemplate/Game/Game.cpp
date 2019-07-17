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
#include "Background.h"

Game::Game()
{
}


Game::~Game()
{
	TK_LOG("~Game()");
	DeleteGOs("gcamera");
	DeleteGOs("player");
	DeleteGOs("gamedata");
	DeleteGOs("scope");
	DeleteGOs("status");
	DeleteGOs("penG");
	DeleteGOs("level");
	DeleteGOs("EffectManager");
	DeleteGOs("light");
	DeleteGOs("background");
	DeleteGOs("children");
	DeleteGOs("it");
	DeleteGOs("woman");
	DeleteGOs("man");
	DeleteGOs("result");
	

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

	//1�{��
	auto dirLig = NewGO<prefab::CDirectionLight>(0, "light");
	dirLig->SetColor({5.0f, 5.0f, 5.0f, 1.0f});
	CVector3 dir = { 1.0f, -1.0f, 1.0f };
	dir.Normalize();
	dirLig->SetDirection(dir);
	//2�{��
	dirLig = NewGO<prefab::CDirectionLight>(0, "light");
	dirLig->SetColor({ 2.0f, 2.0f, 2.0f, 1.0f });
	dir = { -1.0f, -1.0f, -1.0f };
	dir.Normalize();
	dirLig->SetDirection(dir);

	//3�{��
	dirLig = NewGO<prefab::CDirectionLight>(0, "light");
	dirLig->SetColor({ 2.0f, 2.0f, 2.0f, 1.0f });
	dir = { 1.0f, -1.0f, 1.0f };
	dir.Normalize();
	dirLig->SetDirection(dir);

	return true;
}

void Game::Update()
{
}