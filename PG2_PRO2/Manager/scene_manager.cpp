#include "scene_manager.h"

SceneManager::SceneManager()
{
	Init();
    gameclear = new GameClear();
    gameover = new Gameover();
	title = new Title();

}
SceneManager::~SceneManager()
{
    delete game;
    delete title;
    delete gameclear;
    delete gameover;
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


	//TESTシーン切り替え
	if (keys[DIK_TAB] && !preKeys[DIK_TAB]) {
		if (current_scene != SceneState::GAMEOVER) {
			current_scene = SceneState((int)current_scene + 1);
		}
		else {
			current_scene = SceneState::TITLE;
		}
	}


	switch (current_scene) {
	case SceneState::TITLE:
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			current_scene = SceneState::ARCADE;
		}
		break;
	case SceneState::ARCADE:
		if (keys[DIK_BACKSPACE] && !preKeys[DIK_BACKSPACE]) {
			current_scene = SceneState::TITLE;
		}
		game->Update();
        if (game->GetEnemyDeathCount() == 20) {
            current_scene = SceneState::GAMECLEAR;
        }
        if (game->GetPlayer()->GetHP() <= 0) {
            current_scene = SceneState::GAMEOVER;
        }
		break;
	case SceneState::GAMECLEAR:
		game->Init();
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			current_scene = SceneState::TITLE;
		}
		break;
	case SceneState::GAMEOVER:
		game->Init();
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			current_scene = SceneState::TITLE;
		}
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
		title->Render();
		break;
	case SceneState::ARCADE:
		game->Render();
		Novice::ScreenPrintf(0, 40, "20 TO WIN");
		break;
	case SceneState::GAMECLEAR:
		gameclear->Render();
		break;
	case SceneState::GAMEOVER:
        gameover->Render();
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