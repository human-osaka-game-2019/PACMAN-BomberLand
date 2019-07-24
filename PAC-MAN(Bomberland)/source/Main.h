#ifndef MAIN_H_
#define MAIN_H_

#include <windows.h>
#include <tchar.h>

#include "DirectX.h"

using DX::DirectX;

DirectX dx;

//!ウィンドウの横幅
const INT window_width = 1920;

//!ウィンドウの縦幅
const INT window_height = 1080;

enum SCENE {
	Title,
	Information,
	Game,
	GameClear,
	GameOver
};

SCENE g_scene = Title;

SCENE SwitchScene(SCENE);

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
