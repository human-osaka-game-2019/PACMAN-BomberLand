#ifndef MAIN_H_
#define MAIN_H_

#include <windows.h>
#include <tchar.h>

#include "../../DirectX/DirectX.h"
#include "../source/Scene.h"

using DX::DirectX;

extern DirectX dx;

extern RECT WinRect;

#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080

extern SCENE_BASE::SCENE g_scene;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

/*
*@brief ウィンドウ生成
*@param ハンドルインスタンスのポインタ変数
*@param アプリケーションの名前
*@return ウィンドウハンドル
*/
HWND GenerateWindow(HINSTANCE* hInstance,const TCHAR* API_NAME);

#endif //MAIN_H_
