#include "../Main.h"
#include "Game.h"

void GAME::UpdateScene() {
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

void GAME::Load() {
	dx.LoadTexture("resource/Map/map.png", "map_BG");
	dx.LoadTexture("resource/Map/wall.png", "wall");
	dx.LoadTexture("resource/Character/Player/Player.png", "Player");
	step = MainStep;
}

void GAME::Control() {

	player.Move();

#ifdef _DEBUG
	if (dx.KeyState[DIK_SPACE] == dx.PUSH) {
		step = ReleaseStep;
	}
#endif
}

void GAME::Draw() {
	MAP map[18][34];
	for (int row = 0; row < 18; row++) {
		for (int col = 0; col < 34; col++) {
			if (col % 2 == 0 || row % 2 == 0) {
				dx.Draw(map_width * col + width_margin / 2, map_height * row + height_margin / 2, map_width, map_height, 0.0f, 1.0f, false, "wall");
			}
			else {
				dx.Draw(map_width * col + width_margin / 2, map_height * row + height_margin / 2, map_width, map_height, 0.0f, 1.0f, false, "map_BG");
			}
		}
	}
	frame++;
	player.Animation(frame,3,"Player");
	if (frame == 12) {
		frame = 0;
	}

}

void GAME::Release() {
	dx.ReleaseTexture("map_BG");
	dx.ReleaseTexture("Player");
}

GAME::GAME():map_width(50),map_height(50),frame(0),width_margin(window_width - 1700),height_margin(window_height - 900){

}

GAME::~GAME() {

}