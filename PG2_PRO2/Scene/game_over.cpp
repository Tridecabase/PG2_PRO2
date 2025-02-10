#include "game_over.h"

Gameover::~Gameover()
{
}

void Gameover::Init()
{
}

void Gameover::Update()
{
}

void Gameover::Render()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xF2E4D4FF, kFillModeSolid);
	Novice::ScreenPrintf(10, 10, "GAME OVER");
	Novice::ScreenPrintf(10, 30, "PRESS TAB TO CONTINUE");
}
