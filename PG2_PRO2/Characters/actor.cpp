#include "Actor.h"

Actor::Actor(const ActorState& state) 
	: s(state), isHit(false), isAlive(true), 
	current_mode(BlendMode::kBlendModeNone) {}

void Actor::Update()
{
	if (isAlive)
	{
		//HPが0になった時消える
		if (s.hp <= 0) {
			s.hp = 0;
			isAlive = false;
		}
	}
}

void Actor::UpdateState(const ActorState& newState)
{
	s = newState;
}

void Actor::MoveDir(float dirX, float dirY)
{
	s.x += s.vx * dirX;
	s.y += s.vy * dirY;
}

void Actor::Input()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

void Actor::TakeDamage(int damage)
{
	s.hp -= damage;
}

void Actor::Render()
{
	if (showCollisionBox)
	{
		if (!isHit)
		{
			Novice::DrawEllipse(
				static_cast<int>(s.x),
				static_cast<int>(s.y),
				static_cast<int>(s.radius),
				static_cast<int>(s.radius),
				s.angle,
				GetRGBA(),
				kFillModeWireFrame
			);
		}
		else
		{
			Novice::DrawEllipse(
				static_cast<int>(s.x),
				static_cast<int>(s.y),
				static_cast<int>(s.radius),
				static_cast<int>(s.radius),
				s.angle,
				RED,
				kFillModeWireFrame
			);
		}
	}
}