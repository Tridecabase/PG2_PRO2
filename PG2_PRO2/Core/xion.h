#pragma once

#ifdef _DEBUG
#include <imgui.h>
#endif

#define _USE_MATH_DEFINES
#include <Novice.h>
#include "Vector2.h"
#include <math.h>
#include <time.h>
#include <string>
#include <vector>
#include <Memory>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>

#include "structs.h"
#include "enum.h"

/* +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
 * 				    エラーハンドリングマクロ
 * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 *
 * 指定したエラー情報と詳細を基に、ファイル名・行番号を付加して
 * `std::logic_error` をスローするマクロです。
 *
 */
#define THROW_ERROR(error_info, error_detail)   \
    do{                                         \
    std::string info = "parse error in ";       \
    std::string file_pos = __FILE__;            \
    file_pos.append(":");                       \
    file_pos.append(std::to_string(__LINE__));  \
    info += file_pos;                           \
    info += ", ";                               \
    info += (error_info);                       \
    info += "\ndetail:";                        \
    info += (error_detail);                     \
    throw std::logic_error(info);               \
}while(false)



/*
 * このヘッダファイルは、ゲームの基本的な定数を定義しています。
 *
 * 【使い方】
 * 1. ファイルに `#include "./Core/xion.h"` でインクルードします。
 * 2. 定義された定数は直接使用できます。例: `WINDOW_WIDTH`, `VOLUME_MUSIC`。
 *
 * 【注意】
 * - 定数は変更できないため、動的に変更したい場合は新たな変数を用意してください。
 *
 * このファイルを使うことで、ゲームの基本設定を一元管理できます。
 */
 ////////////////////////////////////////////////////////////////////////////////////////////
 //↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ウィンドウ設定↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
 ////////////////////////////////////////////////////////////////////////////////////////////

//ウィンドウのサイズ
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;



////////////////////////////////////////////////////////////////////////////////////////////
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓フレーム設定↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
////////////////////////////////////////////////////////////////////////////////////////////

//ゲームフレームレート
const int FRAME_RATE = 60;
//毎フレームの秒経過
const float DELTA_TIME = 1.0f / 60.0f;


////////////////////////////////////////////////////////////////////////////////////////////
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ゲームステージ設定↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
////////////////////////////////////////////////////////////////////////////////////////////

//最大速度
const float MAX_SPEED = 100.0f;



////////////////////////////////////////////////////////////////////////////////////////////
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓アイテム設定↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓プレイヤー設定↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
////////////////////////////////////////////////////////////////////////////////////////////

//プレイヤーの基準攻撃力
const int PLAYER_BASE_DAMAGE = 10;



////////////////////////////////////////////////////////////////////////////////////////////
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓敵設定↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓//
////////////////////////////////////////////////////////////////////////////////////////////




