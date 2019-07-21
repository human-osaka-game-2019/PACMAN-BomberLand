#ifndef MAIN_H_
#define MAIN_H_

#include <windows.h>
#include <tchar.h>

const INT Width = 1280; //!ウィンドウの横幅
const INT Height = 720; //!ウィンドウの縦幅

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

#endif
