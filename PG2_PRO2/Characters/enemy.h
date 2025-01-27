#ifndef ENEMY_H
#define ENEMY_H

#include "actor.h"

class Enemy : public Actor
{
public:
	Enemy(const ActorState& state);
	~Enemy() = default;

	void Update() override;

private:
	float direction = 1.0f;
};

#endif // !ENEMY_H
