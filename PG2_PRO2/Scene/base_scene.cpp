#include "base_scene.h"

BaseScene::BaseScene()
	:back_color(0X000000FF){}

BaseScene::~BaseScene()
{
}

void BaseScene::Init()
{
}

void BaseScene::Update()
{
}

void BaseScene::Render()
{
	Novice::DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, back_color, kFillModeSolid);
}
