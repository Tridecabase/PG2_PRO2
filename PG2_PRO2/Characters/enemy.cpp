#include "enemy.h"

Enemy::Enemy(const ActorState& state)
	: Actor(state)
{
	isAlive = true;
}

void Enemy::Update()
{
	MoveDir(1.0f, direction);
	if (s.x<s.radius || s.x>WINDOW_WIDTH - s.radius) {
		direction *= -1;
	}
}
