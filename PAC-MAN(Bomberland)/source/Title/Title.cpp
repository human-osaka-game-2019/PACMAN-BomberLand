#include "../Main.h"
#include "Title.h"

void TITLE::UpdateScene() {
	switch (step) {
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

void TITLE::Load() {
	dx.LoadTexture("resource/BackGround/Title_BG.png", "Title_BG");
	dx.LoadTexture("resource/Logo/TitleLogo.png", "TitleLogo");
	dx.LoadTexture("resource/Ui/push_space.png", "PushSpace");

	step = MainStep;
}

void TITLE::Control() {
	if (dx.KeyState[DIK_SPACE] == dx.PUSH) {
		step = ReleaseStep;
	}
}

void TITLE::Draw() {
	dx.Draw(0, 0, window_width, window_height, 0.0f, 1.0f, false, "Title_BG");
	dx.Draw(160, 45, 1600, 250, 0.0f, 1.0f, false, "TitleLogo");
	dx.Draw(310, 880, 1300, 150, 0.0f, 1.0f, false, "PushSpace");
}

void TITLE::Release() {
	dx.ReleaseTexture("Title_BG");
	g_scene = Information;
}

TITLE::TITLE() {
	
}

TITLE::~TITLE() {
	
}


