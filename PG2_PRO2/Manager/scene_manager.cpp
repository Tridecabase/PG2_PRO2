#include "scene_manager.h"

SceneManager::SceneManager()
{
	Init();
}
SceneManager::~SceneManager()
{
}

////////////////////////////////////////////////////////////////////////////////////////////
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓初期化はここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
////////////////////////////////////////////////////////////////////////////////////////////

void SceneManager::Init() {

	//初期シーンを設定
	current_scene = SceneState::TITLE;
	game = new Game();
}

////////////////////////////////////////////////////////////////////////////////////////////
//↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑初期化はここまで↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑//
////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓更新処理ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
////////////////////////////////////////////////////////////////////////////////////////////

void SceneManager::Update(char keys[256], char preKeys[256]) {

#ifdef _DEBUG
	//TESTシーン切り替え
	if (keys[DIK_TAB] && !preKeys[DIK_TAB]) {
		if (current_scene != SceneState::GAMEOVER) {
			current_scene = SceneState((int)current_scene + 1);
		}
		else {
			current_scene = SceneState::TITLE;
		}
	}
#endif

	switch (current_scene) {
	case SceneState::TITLE:

		break;
	case SceneState::ARCADE:
		game->Update();
		break;
	case SceneState::GAMECLEAR:

		break;
	case SceneState::GAMEOVER:

		break;
	default:

		break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
//↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑更新処理ここまで↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑//
////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓描画処理ここから↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
////////////////////////////////////////////////////////////////////////////////////////////

void SceneManager::Render() {
#ifdef _DEBUG
	DebugInfo();
#endif

	switch (current_scene) {
	case SceneState::TITLE:
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xF2D7D5FF, kFillModeSolid);
		break;
	case SceneState::ARCADE:
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xE8D4F9FF, kFillModeSolid);
		game->Render();
		break;
	case SceneState::GAMECLEAR:
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xD4F9F2FF, kFillModeSolid);
		break;
	case SceneState::GAMEOVER:
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xF2E4D4FF, kFillModeSolid);
		break;
	default:
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xA0A0A0FF, kFillModeSolid);
		break;
	}
}

void SceneManager::DebugInfo() {
#ifdef _DEBUG
	ImGui::Begin("SceneManager");
	ImGui::Text("Current Scene: %s", toString(current_scene).c_str());
	if (ImGui::Button("change scene", ImVec2(100, 20))) {
		//TESTシーン切り替え
		if (current_scene != SceneState::GAMEOVER) {
			current_scene = SceneState((int)current_scene + 1);
		}
		else {
			current_scene = SceneState::TITLE;
		}
	}
	ImGui::End();
#endif
}

////////////////////////////////////////////////////////////////////////////////////////////
//↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑描画処理ここまで↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑//
////////////////////////////////////////////////////////////////////////////////////////////

void SceneManager::ChangeScene(SceneState newScene) {
	current_scene = newScene;
}