#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Utility/Vec.h"
#include "../Utility/Size.h"

struct Anime {
	int frame;
	const int change_frame;
	bool is_loop;
	Vec2 UV;

	Anime();
};

class PLAYER {
public:
	enum DIRECTION {
		RIGHT = 0,
		DOWN = 90,
		LEFT = 180,
		UP = 270
	};

	Anime anime;
	float Texture_U = 0.0f;
	float Texture_V = 0.0f;
	const float Texture_WU = 32.0f / 1024.0f;
	const float Texture_HV = 32.0f / 1024.0f;

	PLAYER();
	~PLAYER();

	Vec2 GetPos();
	void SetPos(float x, float y);
	Size GetSize();
	void SetSize(float width, float height);
	float GetSpeed();
	void SetSpeed(float speed);
	void SetDirection(DIRECTION direction);
	int GetLiveCount();
	void SetLiveCount(int LiveCount);
	void Animation(std::string TextureName);
	void Move();

private:
	Vec2 pos;
	Size size;
	DIRECTION direction;
	int LiveCount;
	float speed = 7.5f;
};

class ENEMY_BASE {
public:
	Vec2 GetPos();
	void SetPos();
	Size GetSize();
	void SetSize();

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

class COOKIE {
public:
	bool is_dead;

	Vec2 GetPos();
	void SetPos(float x, float y);

	COOKIE();

private:
	Vec2 CenterPos;
	const Size size;
};

#endif //CHARACTER_H_