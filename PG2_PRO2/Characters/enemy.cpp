#include "enemy.h"

Enemy::Enemy(const ActorState& state)
	: Actor(state)
{
	isAlive = true;
	box = new CollisionBox(Vector2{ s.x - s.radius, s.y - s.radius }, s.radius * 2, s.radius * 2, CollisionLayer::ENEMY);
	CollisionManager::GetInstance().AddCollisionBox(box);
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

	box->SetPosition({ s.x - s.radius, s.y - s.radius });
}

void Enemy::Render()
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
		color,kFillModeSolid
	);
}

void Enemy::DebugInfo()
{
#ifdef _DEBUG
	ImGui::Begin("Enemy");
	ImGui::DragInt("hp", &s.hp, 2.0f, 0, 100, "%d", ImGuiSliderFlags_None);
	ImGui::DragFloat("y", &s.y, 2.0f, -static_cast<float>(WINDOW_HEIGHT), static_cast<float>(WINDOW_HEIGHT), "%f", ImGuiSliderFlags_None);
	ImGui::End();
#endif
}