#include "player.h"

Player::Player(const ActorState& state)
{
	s = state;
	color = (s.r << 24) | (s.g << 16) | (s.b << 8) | s.a;
	wirecolor = 0x191B19FF;
}

Player::~Player()
{
}

void Player::Update()
{
	Actor::Update();
	Actor::Input();

	if (keys[DIK_W] || preKeys[DIK_W])
	{
		s.y -= s.vy;
	}
	if (keys[DIK_S] || preKeys[DIK_S])
	{
		s.y += s.vy;
	}
	if (keys[DIK_A] || preKeys[DIK_A])
	{
		s.x -= s.vx;
	}
	if (keys[DIK_D] || preKeys[DIK_D])
	{
		s.x += s.vx;
	}

	if (!keys[DIK_W] && !keys[DIK_S] && !keys[DIK_A] && !keys[DIK_D]) {
		current_mode = BlendMode::kBlendModeAdd;
	}
	else {
		current_mode = BlendMode::kBlendModeNone;
	}
}

void Player::Render()
{
	DrawStar(s.x, s.y, s.radius, s.angle, color, wirecolor, current_mode);
	Actor::Render();
}
