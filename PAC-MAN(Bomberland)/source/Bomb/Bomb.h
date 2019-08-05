#ifndef BOMB_H_
#define BOMB_H_
#include "../Utility/Vec.h"
#include "../Utility/Size.h"

class BOMB
{
public:
	Vec2 pos;
	Vec2 CenterPos;
	Size size;
	int LiveCount;
	bool is_Dead;

	BOMB();
	~BOMB();
};


#endif //BOMB_H_