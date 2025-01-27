#include "game.h"

Game::Game() : enemy_distance(40.0f)
{
	back_color = 0xE8D4F9FF;
	Init();
}

Game::~Game()
{
	enemy.clear();
}

void Game::Init()
{
	for (int i = 0; i < MAX_ENEMY; i++) 
	{
		ActorState enemy_state = { WINDOW_WIDTH - i * enemy_distance,100.0f + i * 5.0f,10.0f,10.0f,30.0f,0.0f,0xff,0xff,0xff,0x44,100,100 };
		auto e = std::make_unique<Enemy>(enemy_state);
		enemy.push_back(std::move(e));
	}

	ActorState player_state ={ WINDOW_WIDTH / 2 ,WINDOW_HEIGHT - 100.0f,10.0f,10.0f,30.0f,0.0f,0xff,0xff,0xff,0x44,100,100 };
	player = std::make_unique<Player>(player_state);
}

void Game::Update()
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update();
		}
	}
	player->Update();
}

void Game::Render()
{
	BaseScene::Render();
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Render();
		}
	}
	player->Render();
}
