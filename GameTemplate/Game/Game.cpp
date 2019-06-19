#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "GameData.h"
#include "Player.h"
#include "Status.h"
#include "Background.h"
#include "PenGenerator.h"
#include "Scope.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}


Game::~Game()
{
	DeleteGOs("gcamera");
	DeleteGOs("player");
	DeleteGOs("back");
	DeleteGOs("gamedata");
	DeleteGOs("scope");
	DeleteGOs("status");
	DeleteGOs("penG");
}
bool Game::Start()
{
	NewGO<GameCamera>(0, "gcamera");
	NewGO<Background>(0, "back");
	NewGO<Player>(0, "player");
	NewGO<Scope>(0, "scope");
	NewGO<Status>(0, "status");
	NewGO<GameData>(0, "gamedata");
	NewGO<PenGenerator>(0, "penG");
	return true;
}

void Game::Update()
{

}