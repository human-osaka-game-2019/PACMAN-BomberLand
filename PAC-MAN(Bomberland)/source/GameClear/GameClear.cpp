#include "../Main.h"
#include "GameClear.h"

void GAMECLEAR::UpdateScene() {
	switch (step)
	{
	case LoadStep:Load();
		break;
	case MainStep:
		Control();
		Draw();
		break;
	case ReleaseStep:Release();
		break;
	default:Release();
		break;
	}
}

void GAMECLEAR::Load() {
	dx.LoadTexture("resource/BackGround/Information.png", "Info_BG");
}

void GAMECLEAR::Control() {
	if (dx.KeyState[DIK_SPACE] == dx.PUSH) {
		step = ReleaseStep;
	}
}

void GAMECLEAR::Draw() {
	dx.Draw(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 1.0f, false, "Info_BG");
}

void GAMECLEAR::Release() {
	dx.ReleaseTexture("Info_BG");
}

GAMECLEAR::GAMECLEAR() {

}

GAMECLEAR::~GAMECLEAR() {

}
