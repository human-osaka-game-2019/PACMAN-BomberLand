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
	dx.LoadTexture("resource/Map/Cookie.png", "Cookie");
	step = MainStep;
}

void GAME::Control() {

	player.Move();

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

	player.Animation("Player");

	if (!cookie_is_dead) {
		dx.DrawCenter(cookie_pos.X, cookie_pos.Y, cookie_size.Width, cookie_size.Height, 0.0f, 1.0f, false, "Cookie");
	}

	if (sqrt(cookie_r + player_r) > (double)sqrt(cookie_pos.X - player.GetPos().X) + (double)sqrt(cookie_pos.Y - player.GetPos().Y)) {
		cookie_is_dead = true;
	}

	

}

void GAME::Release() {
	dx.ReleaseTexture("Cookie");
	dx.ReleaseTexture("Player");
	dx.ReleaseTexture("wall");
	dx.ReleaseTexture("map_BG");

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