#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "Core/xion.h"
#include "collision_box.h"
#include "collision.h"
#include "Characters/actor.h"

class CollisionManager
{
public:
    CollisionManager() {}
    ~CollisionManager() {}

    static CollisionManager& GetInstance();

    void AddCollisionBox(CollisionBox* box);
    void RemoveCollisionBox(CollisionBox* box);

    void Update();
    void DevMode();
    bool isBoxShowing = false;
private:

    bool AbleToCollision(CollisionBox* box1, CollisionBox* box2);

    std::vector<CollisionBox*> collisionBoxes;


};

#endif // COLLISION_MANAGER_H