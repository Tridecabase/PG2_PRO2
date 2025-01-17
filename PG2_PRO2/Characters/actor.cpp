#include "Actor.h"

Actor::Actor(const ActorState& state)
{
	s = state;
	isHit = false;
	isAlive = true;
}

void Actor::Update()
{
	Move();
	if (isAlive)
	{
		//HPが0になった時消える
		if (s.hp <= 0) {
			s.hp = 0;
			isAlive = false;
		}
	}
}

void Actor::Move()
{
	if (isAlive)
	{
		//移動処理
		s.x += s.vx;
		s.y += s.vy;
	}
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
	if (isAlive)
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
					(s.r << 24) | (s.g << 16) | (s.b << 8) | s.a,
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
}
