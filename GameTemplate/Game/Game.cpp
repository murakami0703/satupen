#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "Player.h"
#include "Status.h"
#include "Background.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}


Game::~Game()
{
	DeleteGOs("gcamera");
	DeleteGOs("player");
	DeleteGOs("back");
	DeleteGOs("player");
	DeleteGOs("status");
}
bool Game::Start()
{
	NewGO<GameCamera>(0, "gcamera");
	NewGO<Background>(0, "back");
	NewGO<Player>(0, "player");
	NewGO<Status>(0, "status");
	return true;
}

void Game::Update()
{
}