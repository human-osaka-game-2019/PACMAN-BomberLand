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
		Vec2 pos = { 0.0f,0.0f };
		const Size size = { 50.0f,50.0f };
		Vec2 CenterPos = { pos.X + size.Width / 2 , pos.Y + size.Height };
	};

	const float window_width;
	const float window_height;
	const float width_margin;
	const float height_margin;
	bool is_clear;

	BOMB bomb;
	PLAYER player;
	ENEMY_PINK enemy_pink;
	COOKIE cookie[512];

	void Load();
	void Control();
	void Draw();
	void Release();

	void DrawLiveCount();
	void JudgeWall();

};

#endif //GAME_H_
