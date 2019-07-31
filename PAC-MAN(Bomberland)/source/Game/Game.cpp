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
	JudgeWall();

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
	DrawLiveCount();
	frame++;
	player.Animation(frame,3);
	if (frame == 12) {
		frame = 0;
	}

}

void GAME::Release() {
	dx.ReleaseTexture("Player");
	dx.ReleaseTexture("map_BG");
	dx.ReleaseTexture("wall");
}

void GAME::DrawLiveCount() {
	for (int i = 0; i < player.GetLiveCount(); i++) {
		dx.DrawEx(1200 + (i * LiveCount_width), 980 + (i * LiveCount_height), 0.0f, LiveCount_width, LiveCount_height, 0.0f, 1.0f, false, "Player", 0.0f, 0.0f, 0.25f, 0.25f);
	}
}

void GAME::JudgeWall() {
	if (player.GetPos().X < width_margin / 2) {
		player.SetPos(width_margin / 2, player.GetPos().Y);
	}
	if (player.GetPos().X > window_width - width_margin / 2 - player.GetSize().Width) {
		player.SetPos(window_width - width_margin / 2 - player.GetSize().Width, player.GetPos().Y);
	}
	if (player.GetPos().Y < height_margin / 2) {
		player.SetPos(player.GetPos().X, height_margin / 2);
	}
	if (player.GetPos().Y > window_height - height_margin / 2 - player.GetSize().Height) {
		player.SetPos(player.GetPos().X, window_height - height_margin / 2 - player.GetSize().Height);
	}
}

GAME::GAME():map_width(50),map_height(50),frame(0),width_margin(window_width - 1700),height_margin(window_height - 900),LiveCount_width(60),LiveCount_height(60){

}

GAME::~GAME() {

}