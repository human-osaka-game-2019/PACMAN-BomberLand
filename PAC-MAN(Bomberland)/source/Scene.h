#ifndef SCENE_H_
#define SCENE_H_

class SCENE_BASE {
public:
	SCENE_BASE();

	~SCENE_BASE();

protected:
	enum STEP {
		LoadStep,
		MainStep,
		ReleaseStep
	};
	STEP step = LoadStep;
private:

};

#endif
