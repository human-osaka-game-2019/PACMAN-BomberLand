#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Utility/Vec.h"
#include "../Utility/Size.h"

struct Anime {
	int frame;
	const int change_frame;
	bool is_loop;
	Vec2 UV;

	//void Animation();

	Anime();
};

struct MapPos {
	int Col, Row;
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
	const float Texture_WU = 64.0f / 1024.0f;
	const float Texture_HV = 64.0f / 1024.0f;

	const float radius;

	PLAYER();
	~PLAYER();

	Vec2 GetPos();
	void SetPos(float x, float y);
	Vec2 GetCenterPos();
	void SetCenterPos(float x, float y);
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
	Vec2 CenterPos;
	Size size;
	DIRECTION direction;
	int LiveCount;
	float speed = 2.0f;
};

class ENEMY_BASE {
public:

	enum DIRECTION {
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

	Vec2 GetPos();
	void SetPos(float x, float y);
	MapPos GetMapPos();
	void SetMapPos(int col, int row);
	Size GetSize();
	void SetSize(float width, float height);
	virtual void Animation() = 0;

protected:
	Vec2 pos;
	MapPos map_pos;
	Size size;
private:

};

class ENEMY_PINK:public ENEMY_BASE {
public: void Animation();
};

class ENEMY_BRUE:public ENEMY_BASE {
public: void Animation();
};

class ENEMY_YELLOW:public ENEMY_BASE {
public: void Animation();
};

class ENEMY_RED:public ENEMY_BASE {
public: void Animation();
};

class COOKIE {
public:
	bool is_dead;
	const float radius;

	Vec2 GetPos();
	void SetPos(float x, float y);
	Size GetSize();

	COOKIE();

private:
	Vec2 CenterPos;
	const Size size;
};

#endif //CHARACTER_H_