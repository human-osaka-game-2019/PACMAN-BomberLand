#include "Main.h"
#include "Title.h"

void TITLE::UpdateScene() {
	switch (step) {
	case LoadStep:Loading();
		break;
	case MainStep:
		Control();
		Draw();
		break;
	case ReleaseStep:Release();
		break;
	}
}

void TITLE::Loading() {
	dx.LoadTexture("Title_BG.jpg", "Title_BG");
	step = MainStep;
}

void TITLE::Draw() {
	dx.Draw(0, 0, window_width, window_height, 0.0f, 0.0f, false, "Title_BG");
}

void TITLE::Control() {
	if (dx.GetKeyState[DIK_SPACE] == dx.ON) {
		step = ReleaseStep;
	}
}

void TITLE::Release() {
	dx.pTexture["Title_BG"]->Release();
	g_scene = Information;
}

TITLE::TITLE() {
	
}

TITLE::~TITLE() {
	
}


