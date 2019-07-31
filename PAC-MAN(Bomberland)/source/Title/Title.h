#ifndef TITLE_H_
#define TITLE_H_

#include "../Scene.h"
#include "../Ui/Ui.h"

class TITLE :public SCENE_BASE {
public:

	TITLE();

	~TITLE();

	void UpdateScene();


private:

	STEP step = LoadStep;

	UI start_ui;

	void Load();
	void Control();
	void Draw();
	void Release();

};


#endif //TITLE_H_
