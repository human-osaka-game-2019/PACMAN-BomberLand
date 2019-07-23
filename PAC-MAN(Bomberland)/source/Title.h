#ifndef TITLE_H_
#define TITLE_H_

class TITLE {
public:
	TITLE();

	~TITLE();

	void UpdateTitleScene();


private:
	enum STEP {
		LoadStep,
		MainStep,
		ReleaseStep
	};
	STEP step = LoadStep;

};


#endif //TITLE_H_
