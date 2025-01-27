#include "player.h"

Player::Player(const ActorState& state)
    : Actor(state),
    wirecolor(0x191B19FF),
    shot_cooldown(0)
{
    bullet_state = { s.x, s.y, 0.0f, 10.0f, 5.0f, 0.0f, 0xff, 0xff, 0xff, 0xff, 1, 1 };
    for (Actor* actor : bullet)
    {
        delete actor;
    }
}

Player::~Player()
{
    for (Actor* actor : bullet)
    {
        delete actor;
    }
    bullet.clear();
}

void Player::Update()
{
	Actor::Update();
    Actor::Input();
    Move();
    Shot();
}

void Player::Move()
{
    if (keys[DIK_W] || preKeys[DIK_W]) {
        MoveDir(0.0f, -1.0f);
    }
    if (keys[DIK_S] || preKeys[DIK_S]) {
        MoveDir(0.0f, 1.0f);
    }
    if (keys[DIK_A] || preKeys[DIK_A]) {
        MoveDir(-1.0f, 0.0f);
    }
    if (keys[DIK_D] || preKeys[DIK_D]) {
        MoveDir(1.0f, 0.0f);
    }

    if (!keys[DIK_W] && !keys[DIK_S] && !keys[DIK_A] && !keys[DIK_D]) {
        SetBlendMode(kBlendModeAdd);
        Rotate(0.01f);
    }
    else {
        SetBlendMode(kBlendModeNone);
        Rotate(0.1f);
    }
}

void Player::Shot()
{
    if (keys[DIK_SPACE] && shot_cooldown == 0) 
    {
        if (bullet.size() < PLAYER_MAX_BULLET)
        {
            bullet_state.x = s.x;
            bullet_state.y = s.y;
            Actor* b = new Bullet(bullet_state);
            bullet.push_back(std::move(b));
            shot_cooldown = BULLET_MAX_COOLDOWN;
        }
    }

    if (shot_cooldown > 0) 
    {
        shot_cooldown--;
    }
    else 
    {
        shot_cooldown = 0;
    }

    for (int i = 0; i < bullet.size(); i++)
    {
        if (bullet[i] != nullptr)
        {
            bullet[i]->Update();
        }
    }

    for (int i = 0; i < bullet.size(); i++)
    {
        if (bullet[i] != nullptr)
        {
            if (!bullet[i]->isAlive) {
                bullet.erase(bullet.begin() + i);
            }
        }
    }
}

void Player::Render()
{
    for (int i = 0; i < bullet.size(); i++)
    {
        if (bullet[i] != nullptr)

        {
            bullet[i]->Render();
        }
    }
    StarGenerator::DrawStar(s.x, s.y, s.radius, s.angle, GetRGBA(), wirecolor, GetBlendMode());
	Actor::Render();
}
