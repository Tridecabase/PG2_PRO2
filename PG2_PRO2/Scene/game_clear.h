#ifndef GAME_CLEAR_H
#define GAME_CLEAR_H

#include "base_scene.h"

class GameClear : public BaseScene
{
public:
	GameClear() = default;
	~GameClear() override;

	void Init() override;
	void Update() override;
	void Render() override;

private:

};

#endif // !GAME_CLEAR_H
