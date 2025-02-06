#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "base_scene.h"

class Gameover : public BaseScene
{
public:
	Gameover() = default;
	~Gameover() override;

	void Init() override;
	void Update() override;
	void Render() override;

private:

};

#endif // !GAME_OVER_H
