#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Utility/Vec.h"
#include "../Utility/Size.h"

class PLAYER {
public:
	enum DIRECTION {
		RIGHT = 0,
		DOWN = 90,
		LEFT = 180,
		UP = 270
	};

	bool is_dead;

	PLAYER();
	~PLAYER();

	Vec2 GetPos();
	void SetPos(float x, float y);
	Size GetSize();
	void SetSize(float width, float height);
	float GetSpeed();
	void SetDirection(DIRECTION direction);
	void Animation(int frame,int pages,std::string TextureName);
private:
	Vec2 pos;
	Size size;
	DIRECTION direction;
	const float speed = 7.5f;
};

class ENEMY_BASE {
public:

protected:
	Vec2 pos;
private:

};

class ENEMY_PINK:public ENEMY_BASE {

};

class ENEMY_BRUE:public ENEMY_BASE {

};

class ENEMY_YELLOW:public ENEMY_BASE {

};

class ENEMY_RED:public ENEMY_BASE {

};

#endif //CHARACTER_H_