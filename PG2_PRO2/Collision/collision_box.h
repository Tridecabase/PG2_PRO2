#ifndef COLLISION_BOX_H
#define COLLISION_BOX_H

#include "Core/xion.h"
#include "Collision/collision_layer.h"


class Actor;
class CollisionBox
{
public:
    CollisionBox(const Vector2& pos, float width, float height, CollisionLayer layer)
        : 
        pos(pos), 
        width(width), 
        height(height), 
        layer(layer),
        color(GREEN),
        isCollided(false),
        isAlive(true)
    {}

    ~CollisionBox() {}

    //位置
    Vector2 GetPosition() const { return pos; }
    void SetPosition(const Vector2& newPos) { pos = newPos; }
    //長さ
    float GetWidth() const { return width; }
    void SetWidth(float newWidth) { width = newWidth; }
    //高さ
    float GetHeight() const { return height; }
    void SetHeight(float newHeight) { height = newHeight; }
    //レイヤ
    CollisionLayer GetLayer() const { return layer; }
    void SetLayer(CollisionLayer newLayer){ layer = newLayer; }
    //色
    unsigned int GetColor() const { return color; }
    void SetColor(unsigned int newColor) { color = newColor; }

public:
    Vector2 pos;
    float width;
    float height; 
    CollisionLayer layer;
    unsigned int color;
    bool isCollided;
    bool isAlive;

    Actor* owner = nullptr;
};
#endif // COLLISION_BOX_H