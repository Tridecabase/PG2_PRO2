#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"
#include "Tools/star_generator.h"

class Player : public Actor
{
public:
	Player(const ActorState& state);
	~Player() override;

	void Update() override;
	void Render() override;

private:
	unsigned int color;
	unsigned int wirecolor;
	BlendMode current_mode;
};

#endif // !PLAYER_H

