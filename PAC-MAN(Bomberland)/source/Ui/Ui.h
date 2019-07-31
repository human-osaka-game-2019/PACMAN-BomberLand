#ifndef UI_H_
#define UI_H_

#include "../Utility/Vec.h"
#include "../Utility/Size.h"

class UI {
private:
	struct Speed {
		float vx, vy;
	};
public:
	UI();
	UI(float x, float y, float width, float height);
	~UI();

	Vec2 GetPos();
	void SetPos(float x, float y);
	Size GetSize();
	void SetSize(float width, float height);
	Speed GetSpeed();
	void SetSpeed(float vx, float vy);
	void JumpUi(float acceleration);

private:
	Vec2 Pos;
	Speed speed;
	Size size;

};

#endif //UI_H_