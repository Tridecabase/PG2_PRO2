#ifndef GAME_H
#define GAME_H

#include "base_scene.h"
#include "Characters/actor.h"
#include "Characters/enemy.h"
#include "Characters/player.h"

class Game : public BaseScene
{
public:
	Game();
	~Game() override;

	void Init() override;
	void Update() override;
	void Render() override;

private:
	std::vector<std::unique_ptr<Actor>> enemy;
	std::unique_ptr<Player> player;
	float enemy_distance;
};

#endif // !GAME_H

