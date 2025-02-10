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
}

bool CollisionManager::AbleToCollision(CollisionBox* box1, CollisionBox* box2)
{
    if (box1->layer == CollisionLayer::ENEMY && box2->layer != CollisionLayer::ENEMY)
        return true;
    if (box2->layer == CollisionLayer::ENEMY && box1->layer != CollisionLayer::ENEMY)
        return true;
    return false;
}

#ifdef _DEBUG
void CollisionManager::DevMode(char keys[256], char preKeys[256])
{
    if (keys[DIK_0] && !preKeys[DIK_0]) 
    {
        isBoxShowing = !isBoxShowing;
    }

    for (size_t i = 0; i < collisionBoxes.size(); ++i)
    {
        Vector2 pos = collisionBoxes[i]->GetPosition();
        Novice::DrawBox(
            static_cast<int>(pos.x),
            static_cast<int>(pos.y),
            static_cast<int>(collisionBoxes[i]->GetWidth()),
            static_cast<int>(collisionBoxes[i]->GetHeight()),
            0.0f,collisionBoxes[i]->color,kFillModeWireFrame);
    }
}
#endif // _DEBUG