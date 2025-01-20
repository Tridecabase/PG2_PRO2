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
	void UpdateState(const ActorState& newState);
	virtual void Move();
	void Input();
	void TakeDamage(int damage);
	void Move(float dx, float dy) {
		s.x += dx;
		s.y += dy;
	}

	void Rotate(float dAngle) {
		s.angle += dAngle;
	}
	/* 描画処理 */
	virtual void Render();

public:

	/* GETTER */
	float GetPosX() const { return s.x; }
	float GetPosY() const { return s.x; }
	float GetVX() const { return s.vx; }
	float GetVY() const { return s.vy; }
	float GetRadius() const { return s.radius; }
	float GetAngle() const { return s.angle; }
	unsigned int GetRGBA(unsigned int r, unsigned int g, unsigned int b, unsigned int a) { return (r << 24) | (g << 16) | (b << 8) | a; }
	int GetHP() const { return s.hp; }
	int GetMaxHP() const { return s.max_hp; }

	/* SETTER */
	void SetPos(float x, float y) { s.x = x; s.y = y; }
	void SetSpeed(float vx, float vy) { s.vx = std::min<float>(MAX_SPEED, std::max<float>(-MAX_SPEED, vx)); s.vy = std::min<float>(MAX_SPEED, std::max<float>(-MAX_SPEED, vy)); }
	void SetRadius(float radius) { s.radius = std::min<float>(1280.0f, std::max<float>(0.0f, radius)); }
	void SetAngle(float angle) { s.angle = angle; }
	void SetRGBA(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
	{
		s.r = std::min<unsigned int>(0xFF, std::max<unsigned int>(0x00, r));
		s.g = std::min<unsigned int>(0xFF, std::max<unsigned int>(0x00, g));
		s.b = std::min<unsigned int>(0xFF, std::max<unsigned int>(0x00, b));
		s.a = std::min<unsigned int>(0xFF, std::max<unsigned int>(0x00, a));
	}
	void SetHP(int hp) { s.hp = std::max<int>(0, std::min<int>(hp, s.max_hp)); }
	void SetMaxHP(int max_hp) { s.max_hp = std::max<int>(0, max_hp); }

	/* データをキャッシュするためのハッシュマップ */
	std::unordered_map<int, Actor> actorCache;

	bool isHit;
	bool isAlive;

	//INPUT
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

private:

	//Actor状態
	ActorState s;
};

#endif // !ACTOR_H