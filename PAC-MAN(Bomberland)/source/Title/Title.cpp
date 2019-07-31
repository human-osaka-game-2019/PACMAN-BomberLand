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
	start_ui.SetPos(310,800);
	start_ui.SetSize(1300,150);
	start_ui.SetSpeed(0,7.5f);

	step = MainStep;
}

void TITLE::Control() {
	start_ui.JumpUi(-0.4f);
	if (start_ui.GetPos().Y > 800) {
		start_ui.SetSpeed(0, 7.5f);
	}

	if (dx.KeyState[DIK_SPACE] == dx.PUSH) {
		step = ReleaseStep;
	}
}

void TITLE::Draw() {
	dx.Draw(0, 0, window_width, window_height, 0.0f, 1.0f, false, "Title_BG");
	dx.Draw(160, 45, 1600, 250, 0.0f, 1.0f, false, "TitleLogo");
	dx.Draw(start_ui.GetPos().X, start_ui.GetPos().Y, start_ui.GetSize().Width, start_ui.GetSize().Height, 0.0f, 1.0f, false, "PushSpace");
}

void TITLE::Release() {
	dx.ReleaseTexture("Title_BG");
	dx.ReleaseTexture("TitleLogo");
	dx.ReleaseTexture("PushSpace");
	g_scene = Information;
}

TITLE::TITLE() {
	
}

TITLE::~TITLE() {
	
}


