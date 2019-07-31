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

	int frame;

	struct MAP {
		Vec2 MapPosition = { 0.0f,0.0f };
	};

	const int width_margin;
	const int height_margin;

	PLAYER player;

	void Load();
	void Control();
	void Draw();
	void Release();

	void DrawLiveCount();
	void JudgeWall();

};

#endif //GAME_H_
