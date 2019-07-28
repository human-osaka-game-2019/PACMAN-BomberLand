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
	Move();

#ifdef _DEBUG
	if (dx.KeyState[DIK_SPACE] == dx.PUSH) {
		step = ReleaseStep;
	}
#endif
}

void GAME::Draw() {
	MAP map[18][32];
	for (int row = 0; row < 18; row++) {
		for (int col = 0; col < 32; col++) {
			if (col % 2 == 0 || row % 2 == 0) {
				dx.Draw(map_width * col, map_height * row, map_width, map_height, 0.0f, 1.0f, false, "wall");
			}
			else {
				dx.Draw(map_width * col, map_height * row, map_width, map_height, 0.0f, 1.0f, false, "map_BG");
			}
		}
	}
	frame++;
	player.Animation(frame, "Player");
	if (frame > 9) {
		frame = 0;
	}

}

void GAME::Release() {
	dx.ReleaseTexture("map_BG");
	dx.ReleaseTexture("Player");
}

void GAME::Move() {
	if (dx.KeyState[DIK_UP] == dx.ON) {
		player.SetPos(player.GetPos().X, player.GetPos().Y - player.GetSpeed());
		player.SetDirection(player.UP);
	}
	if (dx.KeyState[DIK_DOWN] == dx.ON) {
		player.SetPos(player.GetPos().X, player.GetPos().Y + player.GetSpeed());
		player.SetDirection(player.DOWN);
	}
	if (dx.KeyState[DIK_RIGHT] == dx.ON) {
		player.SetPos(player.GetPos().X + player.GetSpeed(), player.GetPos().Y);
		player.SetDirection(player.RIGHT);
	}
	if (dx.KeyState[DIK_LEFT] == dx.ON) {
		player.SetPos(player.GetPos().X - player.GetSpeed(), player.GetPos().Y);
		player.SetDirection(player.LEFT);
	}
}

int GAME::TimeToFrame(float second) {
	return second * 60;
}

GAME::GAME():map_width(60),map_height(60),frame(0){

}

GAME::~GAME() {

}