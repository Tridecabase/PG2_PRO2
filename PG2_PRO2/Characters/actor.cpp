#include "Actor.h"

Actor::Actor(const ActorState& state) 
	: s(state), isHit(false), isAlive(true), 
	current_mode(BlendMode::kBlendModeNone) 
{
	stateRef = state;
}

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

void Actor::UpdateState()
{
	s = stateRef;
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
	if (s.hp < 0) {
		s.hp = 0;
	}

	flashTimer = 3;
}

void Actor::Render()
{
	unsigned int color = GetRGBA();
	if (flashTimer > 0) {
		color = 0xFF0000FF;
		flashTimer--;
	}

	Novice::DrawEllipse(
		static_cast<int>(s.x),
		static_cast<int>(s.y),
		static_cast<int>(s.radius),
		static_cast<int>(s.radius),
		s.angle,
		color,
		kFillModeWireFrame
	);
}

void Actor::OnCollision(Actor* otherActor, int damage)
{
	if (otherActor)
	{
		TakeDamage(damage);
	}
}