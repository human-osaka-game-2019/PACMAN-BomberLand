#ifndef GAME_H_
#define GAME_H_

#include "../Scene.h"
#include "../Utility/Vec.h"
#include "../Character/Character.h"
#include "../Bomb/Bomb.h"

class GAME:public SCENE_BASE {
public:
	GAME();

	~GAME();

	void UpdateScene();

private:

	STEP step = LoadStep;

	const float map_width, map_height;
	const float LiveCount_width, LiveCount_height;

	float BG_tu, BG_tv;

	struct MAP {
		Vec2 MapPosition = { 0.0f,0.0f };
	};

	const float window_width;
	const float window_height;
	const float width_margin;
	const float height_margin;
	bool is_clear;

	Vec2 cookie_pos = {500,500};
	Size cookie_size = {50,50};
	bool cookie_is_dead;
	float cookie_r = cookie_size.Width / 2;

	PLAYER player;
	COOKIE cookie[512];
	float player_r = player.GetSize().Width / 2;

	void Load();
	void Control();
	void Draw();
	void Release();

	void DrawLiveCount();
	void JudgeWall();

};

#endif //GAME_H_
