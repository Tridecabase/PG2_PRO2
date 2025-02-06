#include "enemy.h"

Enemy::Enemy(const ActorState& state)
	: Actor(state)
{
	isAlive = true;
}

void Enemy::Update()
{
	DebugInfo();
	MoveDir(direction, 0.01f);
	if (s.x<s.radius || s.x>WINDOW_WIDTH - s.radius) 
	{
		direction *= -1;
	}
	if (s.y > WINDOW_HEIGHT + s.radius) 
	{
		isAlive = false;
	}
}

void Enemy::Render()
{
	Novice::DrawEllipse(
		static_cast<int>(s.x),
		static_cast<int>(s.y),
		static_cast<int>(s.radius),
		static_cast<int>(s.radius),
		s.angle,
		GetRGBA(),kFillModeSolid
	);
	Actor::Render();
}

void Enemy::DebugInfo()
{
#ifdef _DEBUG
	ImGui::Begin("Enemy");
	ImGui::DragFloat("x", &s.x, 2.0f, 0.0f, static_cast<float>(WINDOW_WIDTH), "%f", 1.0f);
	ImGui::DragFloat("y", &s.y, 2.0f, -static_cast<float>(WINDOW_HEIGHT), static_cast<float>(WINDOW_HEIGHT), "%f", 1.0f);
	ImGui::End();
#endif
}