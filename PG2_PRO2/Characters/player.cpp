#include "player.h"

Player::Player(const ActorState& state)
    : Actor(state),
    color((state.r << 24) | (state.g << 16) | (state.b << 8) | state.a),
    wirecolor(0x191B19FF),
    current_mode(BlendMode::kBlendModeNone) {}

Player::~Player()
{
}

void Player::Update()
{
	Actor::Update();
	Actor::Input();

    if (keys[DIK_W] || preKeys[DIK_W]) {
        Move(0, -GetVY());
        Rotate(0.1f);
    }
    if (keys[DIK_S] || preKeys[DIK_S]) {
        Move(0, GetVY());
        Rotate(0.1f);
    }
    if (keys[DIK_A] || preKeys[DIK_A]) {
        Move(-GetVX(), 0);
        Rotate(0.1f);
    }
    if (keys[DIK_D] || preKeys[DIK_D]) {
        Move(GetVX(), 0);
        Rotate(0.1f);
    }

	if (!keys[DIK_W] && !keys[DIK_S] && !keys[DIK_A] && !keys[DIK_D]) {
		current_mode = BlendMode::kBlendModeAdd;
	}
	else {
		current_mode = BlendMode::kBlendModeNone;
	}

    Rotate(0.01f);
}

void Player::Render()
{
    StarGenerator::DrawStar(
        GetPosX(),
        GetPosY(),
        GetRadius(),
        GetAngle(),
        color,
        wirecolor,
        current_mode
    );
	Actor::Render();
}
