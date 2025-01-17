#ifndef ACTOR_H
#define ACTOR_H

#include "Core/xion.h"

//判定ボックス表示
static bool showCollisionBox;

class Actor {
public:

	/* コンストラクタ(引数なし) */
	Actor() = default;
	Actor(const ActorState& state);
	/* デストラクタ */
	virtual ~Actor() = default;

	/* 更新処理 */
	virtual void Update();
	virtual void Move();
	void Input();
	void TakeDamage(int damage);
	/* 描画処理 */
	virtual void Render();

public:

	///* GETTER */
	//float GetPosX() const { return s.x; }
	//float GetPosY() const { return s.x; }
	//float GetVX() const { return s.vx; }
	//float GetVY() const { return s.vy; }
	//float GetRadius() const { return s.radius; }
	//float GetAngle() const { return s.angle; }
	//unsigned int GetR() const { return s.r; }
	//unsigned int GetG() const { return s.g; }
	//unsigned int GetB() const { return s.b; }
	//unsigned int GetA() const { return s.a; }
	//int GetHP() const { return s.hp; }
	//int GetMaxHP() const { return s.max_hp; }

	///* SETTER */
	//void SetPos(float x, float y) { s.x = x; s.y = y; }
	//void SetSpeed(float vx, float vy) { s.vx = vx; s.vy = vy; }
	//void SetRadius(float radius) { s.radius = radius; }
	//void SetAngle(float angle) { s.angle = angle; }
	//void SetColor(unsigned int r, unsigned int g, unsigned int b, unsigned int a ) { s.r = r; s.g = g; s.b = b; s.a = a; }
	//void SetHP(int hp) { s.hp = hp; }
	//void SetMaxHP(int max_hp) { s.max_hp = max_hp; }

	/* データをキャッシュするためのハッシュマップ */
	std::unordered_map<int, Actor> actorCache;

	bool isHit;
	bool isAlive;

	//INPUT
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//Actor状態
	ActorState s;
};

#endif // !ACTOR_H
