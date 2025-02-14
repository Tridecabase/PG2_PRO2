#include "game.h"

Game::Game()
{
	back_color = 0xE8D4F9FF;
	Init();
}

Game::~Game()
{
	player.reset();
	enemy.clear();
}

void Game::Init()
{
	player.reset();
	enemy.clear();
	//敵の初期化
	std::vector<ActorState> enemyStates = LoadEnemiesFromCSV("./Csv/enemies.CSV");
	for (const auto& state : enemyStates)
	{
		auto e = std::make_unique<Enemy>(state);
		enemy.push_back(std::move(e));
	}
	//プレイヤーの初期化
	ActorState player_state ={ WINDOW_WIDTH / 2 ,WINDOW_HEIGHT - 100.0f,10.0f,10.0f,30.0f,0.0f,0xff,0xff,0xff,0x44,100,100 };
	player = std::make_unique<Player>(player_state);
	enemyDeathCount = 0;
}

void Game::Update()
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i] != nullptr)
		{
			if (!enemy[i]->isAlive)
			{
				enemyDeathCount++;
				enemy[i]->UpdateState();
				enemy[i]->isAlive = true;
			}
			else
			{
				enemy[i]->Update();
			}
		}
	}
	player->Update();

    for (int i = 0; i < enemy.size(); i++)
    {
        if (enemy[i] != nullptr)
        {
            if (Collision::CircleCircle(player->GetPosX(), player->GetPosY(),player->GetRadius(), enemy[i]->GetPosX(), enemy[i]->GetPosY(), enemy[i]->GetRadius()))
            {
                player->TakeDamage(5);
                player->SetRGBA(255, 0, 0, 255);
            }
			else 
			{
                player->SetRGBA(255, 255, 255, 255);
			}
        }
    }

    for (int i = 0; i < enemy.size(); i++)
    {
        if (enemy[i] != nullptr)
        {
            for (int j = 0; j < player->bullet.size(); j++)
            {
                if (Collision::CircleCircle(player->bullet[j]->GetPosX(), player->bullet[j]->GetPosY(), player->bullet[j]->GetRadius(), enemy[i]->GetPosX(), enemy[i]->GetPosY(), enemy[i]->GetRadius()))
                {
                    enemy[i]->TakeDamage(50);
                    player->bullet[j]->isAlive = false;
                }
            }
        }
    }
	
}

void Game::Render()
{ 
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xE8D4F9FF, kFillModeSolid);
	player->Render();
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Render();
		}
	}

	Novice::ScreenPrintf(0, 0, "HP:%d", player->GetHP());
	Novice::ScreenPrintf(0, 20, "count:%d", enemyDeathCount);
}

std::vector<ActorState> Game::LoadEnemiesFromCSV(const std::string& filePath)
{
    std::vector<ActorState> enemyStates;
    CsvParser parser(filePath);
    auto data = parser.Read();

    if (!data.empty()) data.erase(data.begin());

    for (const auto& row : data)
    {
        if (row.size() != 12)
            continue;

        ActorState state;
		state.x = std::stof(row[0]);
		state.y = std::stof(row[1]);
		state.vx = std::stof(row[2]);
		state.vy = std::stof(row[3]);
		state.radius = std::stof(row[4]);
		state.angle = std::stof(row[5]);
		state.r = std::stoi(row[6]);
		state.g = std::stoi(row[7]);
		state.b = std::stoi(row[8]);
		state.a = std::stoi(row[9]);
		state.hp = std::stoi(row[10]);
		state.max_hp = std::stoi(row[11]);

        enemyStates.push_back(state);
    }
    return enemyStates;
}

Player* Game::GetPlayer() const
{
    if (player != nullptr)
	{
		return player.get();
	}
	else 
	{
		return nullptr;
	}
}
