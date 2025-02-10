#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Core/xion.h"
#include "Scene/game.h"
#include "Scene/game_clear.h"
#include "Scene/game_over.h"
#include "Scene/title.h"

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    //シーンの初期化
    void Init();
    //シーンの更新
    void Update(char keys[256], char preKeys[256]);
    //シーンの描画
    void Render();
    void DebugInfo();

private:
    //シーンの状態を表す列挙型
    enum class SceneState {
        TITLE,
        ARCADE,
        GAMECLEAR,
        GAMEOVER,
    };

    void ChangeScene(SceneState newScene);

    //現在のシーン
    SceneState current_scene;
    Title* title;
    GameClear* gameclear;
    Gameover* gameover;

    Game* game;

    const std::unordered_map<SceneState, std::string> SceneStateStrings = {
        {SceneState::TITLE, "TITLE"},
        {SceneState::ARCADE, "ARCADE"},
        {SceneState::GAMECLEAR, "GAMECLEAR"},
        {SceneState::GAMEOVER, "GAMEOVER"},
    };

    std::string toString(SceneState state) {
        return SceneStateStrings.at(state);
    }
};
#endif // SCENE_MANAGER_H