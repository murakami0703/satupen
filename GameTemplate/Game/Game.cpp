#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "GameData.h"
#include "Player.h"
#include "Status.h"
#include "PenGenerator.h"
#include "Scope.h"
#include "Level.h"
#include "tkEngine/light/tkDirectionLight.h"

#include "Background.h"
#include "EnemyChildren.h"
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

}
bool Game::Start()
{
	NewGO<GameCamera>(0, "gcamera");
	NewGO<Player>(0, "player");
	NewGO<Scope>(0, "scope");
	NewGO<Status>(0, "status");
	NewGO<GameData>(0, "gamedata");
	NewGO<PenGenerator>(0, "penG");
	//NewGO<Level>(0, "level");
	NewGO<Background>(0, "back");

	//NewGO<EnemyChildren>(0, "kodo");
	//dbg::SetDrawPhysicsCollisionEnable();
	//1–{–Ú
	auto dirLig = NewGO<prefab::CDirectionLight>(0, "light");
	dirLig->SetColor({5.0f, 5.0f, 5.0f, 1.0f});
	CVector3 dir = { 1.0f, -1.0f, 1.0f };
	dir.Normalize();
	dirLig->SetDirection(dir);
	//2–{–Ú
	dirLig = NewGO<prefab::CDirectionLight>(0, "light");
	dirLig->SetColor({ 2.0f, 2.0f, 2.0f, 1.0f });
	dir = { -1.0f, -1.0f, -1.0f };
	dir.Normalize();
	dirLig->SetDirection(dir);

	//3–{–Ú
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