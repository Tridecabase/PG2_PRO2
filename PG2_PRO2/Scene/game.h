#ifndef GAME_H
#define GAME_H

#include "base_scene.h"
#include "Characters/actor.h"
#include "Characters/enemy.h"
#include "Characters/player.h"
#include "Tools/csv_parser.h"

class Game : public BaseScene
{
public:
	Game();
	~Game() override;

	void Init() override;
	void Update() override;
	void Render() override;

	std::vector<ActorState> LoadEnemiesFromCSV(const std::string& filename);

private:
	std::vector<std::unique_ptr<Actor>> enemy;
	std::unique_ptr<Player> player;
};

#endif // !GAME_H