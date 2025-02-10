#include "title.h"

Title::~Title()
{
}

void Title::Init()
{
}

void Title::Update()
{
}

void Title::Render()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xF2D7D5FF, kFillModeSolid);
	Novice::ScreenPrintf(10, 10, "PRESS TAB TO START");
}
