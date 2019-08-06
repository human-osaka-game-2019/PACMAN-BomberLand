#include "../Main.h"
#include "GameOver.h"

void GAMEOVER::UpdateScene() {
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

void GAMEOVER::Load() {
	dx.LoadTexture("resource/BackGround/Information.png", "Info_BG");
}

void GAMEOVER::Control(){
	if (dx.KeyState[DIK_SPACE] == dx.PUSH) {
		step = ReleaseStep;
	}
}

void GAMEOVER::Draw() {
	dx.Draw(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 1.0f, false, "Info_BG");
}

void GAMEOVER::Release() {
	dx.ReleaseTexture("Info_BG");
}

GAMEOVER::GAMEOVER() {

}

GAMEOVER::~GAMEOVER() {

}
