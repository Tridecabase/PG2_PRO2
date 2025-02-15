#ifndef ACTOR_H
#define ACTOR_H

#include "Core/xion.h"
#include "Collision/collision_manager.h"

class Actor {
public:

	/* コンストラクタ(引数なし) */
	Actor() = default;
	Actor(const ActorState& state);
	/* デストラクタ */
	virtual ~Actor() = default;

	/* 更新処理 */
	virtual void Update();
	void UpdateState();
	void MoveDir(float dirX, float dirY);
	void Input();
	void TakeDamage(int damage);
	void Rotate(float dAngle) { s.angle += dAngle; }
	/* 描画処理 */
	virtual void Render();

	virtual void OnCollision(Actor* otherActor, int damage);

public:

	bool isHit;
	bool isAlive;

	//INPUT
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	/* GETTER */	/* SETTER */
	//色
	unsigned int GetRGBA() const { return (s.r << 24) | (s.g << 16) | (s.b << 8) | s.a; }
	void SetRGBA(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
	{
		s.r = std::min<unsigned int>(0xFF, std::max<unsigned int>(0x00, r));
		s.g = std::min<unsigned int>(0xFF, std::max<unsigned int>(0x00, g));
		s.b = std::min<unsigned int>(0xFF, std::max<unsigned int>(0x00, b));
		s.a = std::min<unsigned int>(0xFF, std::max<unsigned int>(0x00, a));
	}

	//BlendMode
	BlendMode GetBlendMode() const { return current_mode; }
	void SetBlendMode(BlendMode mode) { current_mode = mode; }

	//体力と最大体力
	int GetHP() const { return s.hp; }
	int GetMaxHP() const { return s.max_hp; }
	void SetHP(int hp) { s.hp = std::max<int>(0, std::min<int>(hp, s.max_hp)); }
	void SetMaxHP(int max_hp) { s.max_hp = std::max<int>(0, max_hp); }

	float GetPosX() const { return s.x; };
    float GetPosY() const { return s.y; };
	float GetRadius() const { return s.radius; }

protected:

	//Actor状態
	ActorState s;
	ActorState stateRef;
	BlendMode current_mode;

	int flashTimer = 0;
};

#endif // !ACTOR_H