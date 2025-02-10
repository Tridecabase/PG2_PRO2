#ifndef BULLET_H
#define BULLET_H

#include "actor.h"

class Bullet : public Actor
{
public:
	Bullet(const ActorState& state);
	~Bullet() = default;

	void Update() override;
	void Render() override;

private:
	CollisionBox* box;
};

#endif // !BULLET_H
