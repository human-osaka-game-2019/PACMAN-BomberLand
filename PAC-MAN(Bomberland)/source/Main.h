#ifndef MAIN_H_
#define MAIN_H_

#include <windows.h>
#include <tchar.h>

#include "Title.h"
#include "Game.h"
#include "GameClear.h"
#include "GameOver.h"

//!ウィンドウの横幅
const INT Width = 1920;

//!ウィンドウの縦幅
const INT Height = 1080;

enum SCENE {
	Title,
	Game,
	GameClear,
	GameOver
};

SCENE g_scene = Title;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

/*
*@brief ウィンドウ生成
*@param ハンドルインスタンスのポインタ変数
*@param アプリケーションの名前
*@return ウィンドウハンドル
*/
HWND GenerateWindow(HINSTANCE* hInstance,const TCHAR* API_NAME);

/*
*@brief メインループ
*@param MSGのポインタ変数
*/
VOID Mainloop(MSG* msg);

#endif //MAIN_H_
