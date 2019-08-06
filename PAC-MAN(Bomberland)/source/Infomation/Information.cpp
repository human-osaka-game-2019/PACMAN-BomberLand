#include "../Main.h"
#include "Information.h"

void INFORMATION::UpdateScene() {
	switch (step) {
	case LoadStep:Load();
		break;
	case MainStep:
		Control();
		Draw();
		break;
	case ReleaseStep:Release();
		break;
	}
}

void INFORMATION::Load() {
	dx.LoadTexture("resource/BackGround/Information.png", "Info_BG");
	dx.LoadTexture("resource/Ui/game_rule.png", "game_rule");
	dx.LoadTexture("resource/Ui/push_to_start.png", "Push");
	step = MainStep;
}

void INFORMATION::Draw() {
	dx.Draw(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 1.0f, false, "Info_BG");
	dx.Draw(460, 80, 1000, 200, 0.0f, 1.0f, false, "game_rule");
	dx.Draw(460, 850, 1000, 200, 0.0f, 1.0f, false, "Push");

}

void INFORMATION::Control() {
	if (dx.KeyState[DIK_SPACE] == dx.ON) {
		step = ReleaseStep;
	}
}

void INFORMATION::Release() {
	dx.ReleaseTexture("Info_BG");
	dx.ReleaseTexture("game_rule");
	g_scene = Game;
}

INFORMATION::INFORMATION() {

}

INFORMATION::~INFORMATION() {

}