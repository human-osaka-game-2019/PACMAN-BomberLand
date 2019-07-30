#include "../Main.h"
#include "Character.h"

Vec2 PLAYER::GetPos() {
	return pos;
}

void PLAYER::SetPos(float x, float y) {
	pos.X = x;
	pos.Y = y;
}

Size PLAYER::GetSize() {
	return size;
}

void PLAYER::SetSize(float width, float height) {
	size.Width = width;
	size.Height = height;
}

float PLAYER::GetSpeed() {
	return speed;
}

void PLAYER::SetDirection(PLAYER::DIRECTION direction) {
	this->direction = direction;
}

void PLAYER::Animation(int frame,int pages, std::string TextureName) {
	if (frame < 3) {
		dx.DrawEx(pos.X, pos.Y, 0, size.Width, size.Height, direction, 1.0f, false, TextureName, 0.0f, 0.0f, 0.25f, 0.25f);
	}
	else if (frame >= 3 && frame < 6) {
		dx.DrawEx(pos.X, pos.Y, 0, size.Width, size.Height, direction, 1.0f, false, TextureName, 0.25f, 0.0f, 0.25f, 0.25f);
	}
	else if (frame >= 6 && frame < 9) {
		dx.DrawEx(pos.X, pos.Y, 0, size.Width, size.Height, direction, 1.0f, false, TextureName, 0.5f, 0.0f, 0.25f, 0.25f);
	}
}

void PLAYER::Move() {
	if (dx.KeyState[DIK_UP] == dx.ON) {
		this->SetPos(this->GetPos().X, this->GetPos().Y - this->GetSpeed());
		this->SetDirection(this->UP);
	}
	if (dx.KeyState[DIK_DOWN] == dx.ON) {
		this->SetPos(this->GetPos().X, this->GetPos().Y + this->GetSpeed());
		this->SetDirection(this->DOWN);
	}
	if (dx.KeyState[DIK_RIGHT] == dx.ON) {
		this->SetPos(this->GetPos().X + this->GetSpeed(), this->GetPos().Y);
		this->SetDirection(this->RIGHT);
	}
	if (dx.KeyState[DIK_LEFT] == dx.ON) {
		this->SetPos(this->GetPos().X - this->GetSpeed(), this->GetPos().Y);
		this->SetDirection(this->LEFT);
	}
}

PLAYER::PLAYER():is_dead(false),direction(RIGHT) {
	SetPos(50, 50);
	SetSize(40, 40);
}

PLAYER::~PLAYER() {

}