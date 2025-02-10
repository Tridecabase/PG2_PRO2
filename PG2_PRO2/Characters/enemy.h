#ifndef ENEMY_H
#define ENEMY_H

#include "actor.h"

class Enemy : public Actor
{
public:
	Enemy(const ActorState& state);
	~Enemy() = default;

	void Update() override;
	void Render() override;

private:
	void DebugInfo();
	float direction = 1.0f;

	CollisionBox* box;
};

#endif // !ENEMY_H
