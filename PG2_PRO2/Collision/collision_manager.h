#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "Core/xion.h"
#include "collision_box.h"
#include "collision.h"

class CollisionManager
{
public:
    CollisionManager() {}
    ~CollisionManager() {}

    static CollisionManager& GetInstance();

    void AddCollisionBox(CollisionBox* box);
    void RemoveCollisionBox(CollisionBox* box);

    void Update();

private:

    bool AbleToCollision(CollisionBox* box1, CollisionBox* box2);

    std::vector<CollisionBox*> collisionBoxes;

#ifdef _DEBUG
    void DevMode(char keys[256], char preKeys[256]);
    bool isBoxShowing = false;
#endif // _DEBUG
};

#endif // COLLISION_MANAGER_H