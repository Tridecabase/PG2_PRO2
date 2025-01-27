#include "bullet.h"

Bullet::Bullet(const ActorState& state)
	: Actor(state) 
{
	isAlive = true;
}

void Bullet::Update()
{
	Actor::Update();
	MoveDir(0.0f, -1.0f);

	if (s.y < s.radius) {
		isAlive = false;
	}
}

void Bullet::Render()
{

	Novice::DrawEllipse(
		static_cast<int>(s.x),
		static_cast<int>(s.y),
		static_cast<int>(s.radius),
		static_cast<int>(s.radius),
		s.angle,
		GetRGBA(), kFillModeSolid
	);
	Novice::DrawEllipse(
		static_cast<int>(s.x),
		static_cast<int>(s.y),
		static_cast<int>(s.radius),
		static_cast<int>(s.radius),
		s.angle,
		0x000000ff, kFillModeWireFrame
	);
	Actor::Render();
}
