#include <Novice.h>
#include "Manager/scene_manager.h"
#include "Characters/player.h"

const char kWindowTitle[] = "GC1B_08_ジョ_シセイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WINDOW_WIDTH, WINDOW_HEIGHT);

	std::unique_ptr<SceneManager> sceneManager = std::make_unique<SceneManager>();

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	ActorState player_state =
	{
		100.0f,
		100.0f,
		10.0f,
		10.0f,
		30.0f,
		0.0f,
		0xff,
		0xff,
		0xff,
		0x44,
		100,
		100
	};
	Actor* player = new Player(player_state);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		sceneManager->Update(keys, preKeys);
		player->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		sceneManager->Render();
		player->Render();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
