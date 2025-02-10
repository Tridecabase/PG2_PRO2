#include "collision_manager.h"

CollisionManager& CollisionManager::GetInstance()
{
    static CollisionManager instance;
    return instance;
}

void CollisionManager::AddCollisionBox(CollisionBox* box)
{
	collisionBoxes.push_back(box);
}

void CollisionManager::RemoveCollisionBox(CollisionBox* box)
{
    collisionBoxes.erase(std::remove(collisionBoxes.begin(), collisionBoxes.end(), box), collisionBoxes.end());
}

void CollisionManager::Update()
{
    for (size_t i = 0; i < collisionBoxes.size(); ++i)
    {
        for (size_t j = i + 1; j < collisionBoxes.size(); ++j)
        {
            if (AbleToCollision(collisionBoxes[i], collisionBoxes[j]))
            {
                if (Collision().RectRect(
                    collisionBoxes[i]->pos.x, collisionBoxes[i]->pos.y, collisionBoxes[i]->width, collisionBoxes[i]->height,
                    collisionBoxes[j]->pos.x, collisionBoxes[j]->pos.y, collisionBoxes[j]->width, collisionBoxes[j]->height))
                {
#ifdef _DEBUG
                    collisionBoxes[i]->SetColor(RED);
                    collisionBoxes[j]->SetColor(RED);
#endif // _DEBUG

                    if (collisionBoxes[i]->layer == CollisionLayer::ENEMY &&
                        collisionBoxes[j]->layer == CollisionLayer::BULLET)
                    {
                        Actor* enemy = collisionBoxes[i]->owner;
                        Actor* bullet = collisionBoxes[j]->owner;
                        if (enemy && bullet)
                        {
                            enemy->OnCollision(bullet, 10);
                            bullet->isAlive = false;
                        }
                    }
                    else if (collisionBoxes[i]->layer == CollisionLayer::BULLET &&
                        collisionBoxes[j]->layer == CollisionLayer::ENEMY)
                    {
                        Actor* bullet = collisionBoxes[i]->owner;
                        Actor* enemy = collisionBoxes[j]->owner;
                        if (enemy && bullet)
                        {
                            enemy->OnCollision(bullet, 50);
                            bullet->isAlive = false;
                        }
                    }

                    if (collisionBoxes[i]->layer == CollisionLayer::PLAYER &&
                        collisionBoxes[j]->layer == CollisionLayer::ENEMY)
                    {
                        Actor* player = collisionBoxes[i]->owner;
                        Actor* enemy = collisionBoxes[j]->owner;
                        if (player && enemy)
                        {
                            player->OnCollision(enemy, 50);
                            enemy->OnCollision(player, 100);
                        }
                    }
                    else if (collisionBoxes[i]->layer == CollisionLayer::ENEMY &&
                        collisionBoxes[j]->layer == CollisionLayer::PLAYER)
                    {
                        Actor* enemy = collisionBoxes[i]->owner;
                        Actor* player = collisionBoxes[j]->owner;
                        if (player && enemy)
                        {
                            player->OnCollision(enemy, 50);
                            enemy->OnCollision(player, 100);
                        }
                    }
                }
                else
                {
#ifdef _DEBUG
                    collisionBoxes[i]->SetColor(GREEN);
                    collisionBoxes[j]->SetColor(GREEN);
#endif // _DEBUG
                }
            }
        }
    }
    for (size_t i = 0; i < collisionBoxes.size(); ++i) {
        if (collisionBoxes[i]->owner && !collisionBoxes[i]->owner->isAlive) {
            collisionBoxes.erase(collisionBoxes.begin() + i);
            --i;
        }
    }
}

bool CollisionManager::AbleToCollision(CollisionBox* box1, CollisionBox* box2) {
    return (box1->layer != box2->layer) ||
        (box1->layer == CollisionLayer::BULLET && box2->layer == CollisionLayer::ENEMY) ||
        (box1->layer == CollisionLayer::ENEMY && box2->layer == CollisionLayer::BULLET);
}

void CollisionManager::DevMode()
{
    isBoxShowing = true;

    for (size_t i = 0; i < collisionBoxes.size(); ++i)
    {
        if (collisionBoxes[i]->isAlive)
        {
            Vector2 pos = collisionBoxes[i]->GetPosition();
            Novice::DrawBox(
                static_cast<int>(pos.x),
                static_cast<int>(pos.y),
                static_cast<int>(collisionBoxes[i]->GetWidth()),
                static_cast<int>(collisionBoxes[i]->GetHeight()),
                0.0f, collisionBoxes[i]->color, kFillModeWireFrame);
        }
    }
}