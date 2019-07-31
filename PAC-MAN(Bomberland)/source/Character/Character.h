#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <vector>

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

	PLAYER();
	~PLAYER();

	Vec2 GetPos();
	void SetPos(float x, float y);
	Vec2 GetCenterPos();
	void SetCenterPos(float CenterX, float CenterY);
	Size GetSize();
	void SetSize(float width, float height);
	float GetSpeed();
	void SetDirection(DIRECTION direction);
	int  GetLiveCount();
	void SetLiveCount(int LiveCount);
	void Animation(int frame,int pages);
	void Move();

private:
	Vec2 pos;
	Vec2 CenterPos = {pos.X + size.Width / 2, pos.Y + size.Height / 2};
	Size size;
	DIRECTION direction;
	int LiveCount;
	std::vector<int> AnimeFrame;
	const float speed = 7.5f;
};

class ENEMY_BASE {
public:
	Vec2 GetPos();
	void SetPos(float x, float y);
	Size GetSize();
	void SetSize(float width, float height);
protected:
	Vec2 pos;
	Size size;
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