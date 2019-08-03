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
	dx.LoadTexture("resource/BackGround/Main_bg.jpg", "Main_BG");
	dx.LoadTexture("resource/Map/map.png", "Map_BG");
	dx.LoadTexture("resource/Map/wall.png", "Wall");
	dx.LoadTexture("resource/Character/Player/Player.png", "Player");
	dx.LoadTexture("resource/Map/Cookie.png", "Cookie");

	step = MainStep;
}

void GAME::Control() {

	player.Move();
	JudgeWall();

	BG_tv += 0.00025f;

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

	dx.DrawEx(0, 0, 0, window_width, window_height, 0.0f, 1.0f, false, "Main_BG", BG_tu, BG_tv, 1.0f, 1.0f);

	MAP map[16][32];
	for (int row = 0; row < 16; row++) {
		for (int col = 0; col < 32; col++) {
			if (col % 2 == 0 || row % 2 == 0) {
				dx.Draw(map_width * col + width_margin / 2, map_height * row + height_margin / 2, map_width, map_height, 0.0f, 1.0f, false, "Wall");
			}
			else {

				if (!cookie[col * row].is_dead) {
					cookie[col * row].SetPos(map_width * col + width_margin / 2, map_height * row + height_margin / 2);
				}
				if (sqrt(cookie->radius + player_r) > (double)sqrt(cookie_pos.X - player.GetPos().X) + (double)sqrt(cookie_pos.Y - player.GetPos().Y)) {
					cookie[col * row].is_dead = true;
				}
				
				dx.Draw(cookie[col * row].GetPos().X, cookie[col * row].GetPos().Y, cookie_size.Width, cookie_size.Height, 0.0f, 1.0f, false, "Cookie");
				dx.Draw(map_width * col + width_margin / 2, map_height * row + height_margin / 2, map_width, map_height, 0.0f, 1.0f, false, "Map_BG");
			}
		}
	}

	if (dx.KeyState[DIK_A] == dx.PUSH) {
		player.SetLiveCount(player.GetLiveCount() - 1);
	}

	DrawLiveCount();

	player.Animation("Player");

}

void GAME::Release() {
	dx.ReleaseTexture("Player");
	dx.ReleaseTexture("Cookie");
	dx.ReleaseTexture("Player");
	dx.ReleaseTexture("wall");
	dx.ReleaseTexture("map_BG");
	dx.ReleaseTexture("Main_BG");

	if (is_clear) {
		g_scene = GameClear;
	}
	else {
		g_scene = GameOver;
	}
}

void GAME::DrawLiveCount() {
	for (int i = 0; i < player.GetLiveCount(); i++) {
		dx.DrawEx(1200 + (i * LiveCount_width), 980, 0.0f, LiveCount_width, LiveCount_height, 0.0f, 1.0f, false, "Player", 64.0f / 1024.0f, 0.0f, 64.0f / 1024.0f, 64.0f / 1024.0f);
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

GAME::GAME():map_width(50),map_height(50),
BG_tu(0.0f),BG_tv(0.0f),
window_width(1920),window_height(1080),
LiveCount_width(50),LiveCount_height(50),
width_margin(window_width - 1600),height_margin(window_height - 800),cookie_is_dead(false),
is_clear(false){

}

GAME::~GAME() {

}