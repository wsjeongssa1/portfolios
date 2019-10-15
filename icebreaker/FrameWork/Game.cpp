#pragma once

#include "Include.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	map.Init();
	mapManager.Init();
	//monster.Init();
	sound.Init();
	Gmanager.Init();
	//sql.Init();
}

void Game::Draw()
{
	map.Draw();
	mapManager.Draw();
	//monster.Draw();
	Gmanager.Draw();
	//sql.Draw();
}

void Game::Update(double frame)
{
	key.Update();
	mapManager.Collision();
	mapManager.Update();
	//monster.Update();
	map.Update(frame);
	Gmanager.Update();
	//sql.Update(frame);

	static int a = 0;
	if (a == 0)
	{
		GameTime = GetTickCount();
		a = 1;
	}

}


void Game::OnMessage(MSG* msg)
{

}