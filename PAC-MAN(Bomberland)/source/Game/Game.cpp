?¿#include "../Main.h"
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
	dx.LoadTexture("resource/Map/Cookie.png", "Cookie");
	step = MainStep;
}

void GAME::Control() {

	player.Move();
	JudgeWall();

	if (player.GetLiveCount() == 0) {
		is_clear = false;
		step = ReleaseStep;
	}

#ifdef _DEBUG
	if (dx.KeyState[DIK_SPACE] == dx.PUSH) {
		step = ReleaseStep;
	}
#endif
}

void GAME::Draw() {
	MAP map[16][32];
	for (int row = 0; row < 16; row++) {
		for (int col = 0; col < 32; col++) {
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

	player.Animation("Player");

	if (!cookie_is_dead) {
		dx.DrawCenter(cookie_pos.X, cookie_pos.Y, cookie_size.Width, cookie_size.Height, 0.0f, 1.0f, false, "Cookie");
	}

	if (sqrt(cookie_r + player_r) > (double)sqrt(cookie_pos.X - player.GetPos().X) + (double)sqrt(cookie_pos.Y - player.GetPos().Y)) {
		cookie_is_dead = true;
	}

	

}

void GAME::Release() {
	dx.ReleaseTexture("Player");
	dx.ReleaseTexture("Cookie");
	dx.ReleaseTexture("Player");
	dx.ReleaseTexture("wall");
	dx.ReleaseTexture("map_BG");

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
	if (is_clear) {
		g_scene = GameClear;
	}
	else {
		g_scene = GameOver;
	}
}

GAME::GAME():map_width(50),map_height(50),width_margin(window_width - 1600),height_margin(window_height - 800),cookie_is_dead(false), is_clear(false){

}

GAME::~GAME() {

}