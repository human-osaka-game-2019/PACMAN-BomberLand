#include "Main.h"

#pragma comment(lib,"winmm.lib")

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdline, _In_ INT nCmdShow) {
	const TCHAR API_NAME[] = _T("PAC-MAN ボンバーランド");
	MSG msg;

	HWND hWnd = GenerateWindow(&hInstance, API_NAME);

	Mainloop(&msg);

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		
	case WM_SYSKEYDOWN:
		switch (wp){
		case VK_RETURN:
			return 0;
		case VK_F4:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			return 0;
		default:
			return 0;
		}
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}

HWND GenerateWindow(HINSTANCE* hInstance, const TCHAR* API_NAME) {

	WNDCLASS Wndclass;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = *hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = API_NAME;

	RegisterClass(&Wndclass);

	return CreateWindow(
		API_NAME,
		API_NAME,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,
		0,
		Width,
		Height,
		NULL,
		NULL,
		*hInstance,
		NULL
	);
}

VOID Mainloop(MSG* msg) {
	DWORD Prev = timeGetTime();
	DWORD Curr;

	timeBeginPeriod(1);
	ZeroMemory(msg, sizeof(msg));
	while (msg->message != WM_QUIT){
		if (PeekMessage(msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(msg);
			DispatchMessage(msg);
		}
		else {
			Curr = timeGetTime();
			if (Curr - Prev >= 1000 / 60) {

				Prev = Curr;
			}
		}
		Sleep(1);
	}
	timeEndPeriod(1);
}
