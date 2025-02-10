#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"
#include "bullet.h"
#include "Tools/star_generator.h"

class Player : public Actor
{
public:
	Player(const ActorState& state);
	~Player() override;

	void Update() override;
	void Shot();
	void Move();
	void Render() override;

	void DebugInfo();

	std::vector<Actor*> bullet;

private:
	CollisionBox* box;
	unsigned int wirecolor;
	int shot_cooldown;
	ActorState bullet_state;
	float ra;
};

#endif // !PLAYER_H

