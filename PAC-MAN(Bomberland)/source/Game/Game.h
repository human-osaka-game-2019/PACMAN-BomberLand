#ifndef GAME_H_
#define GAME_H_

#include "../Scene.h"

class GAME:public SCENE_BASE {
public:
	GAME();

	~GAME();

	void UpdateScene();

private:

	STEP step = LoadStep;

	void Load();
	void Draw();
	void Control();
	void Release();

};

#endif
