#ifndef TITLE_H_
#define TITLE_H_

#include "Main.h"

class TITLE {
public:

	TITLE();

	~TITLE();

	void UpdateScene();


private:
	enum STEP {
		LoadStep,
		MainStep,
		ReleaseStep
	};

	bool is_start = true;

	STEP step = LoadStep;
	void Loading();
	void Release();
	void Draw();
	void Control();

};


#endif //TITLE_H_
