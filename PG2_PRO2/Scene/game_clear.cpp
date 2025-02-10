#include "game_clear.h"

GameClear::~GameClear()
{
}

void GameClear::Init()
{
}

void GameClear::Update()
{
}

void GameClear::Render()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xD4F9F2FF, kFillModeSolid);
	Novice::ScreenPrintf(10, 10, "GAME CLEAR");
	Novice::ScreenPrintf(10, 30, "PRESS TAB TO CONTINUE");
}
