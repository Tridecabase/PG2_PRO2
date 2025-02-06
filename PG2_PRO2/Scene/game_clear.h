#ifndef GAME_CLEAR_H
#define GAME_CLEAR_H

#include "base_scene.h"

class Gameclear : public BaseScene
{
public:
	Gameclear() = default;
	~Gameclear() override;

	void Init() override;
	void Update() override;
	void Render() override;

private:

};

#endif // !GAME_CLEAR_H
