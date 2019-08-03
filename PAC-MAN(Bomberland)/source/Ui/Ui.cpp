#include "Ui.h"

Vec2 UI::GetPos() {
	return Pos;
}

void UI::SetPos(float x, float y) {
	this->Pos.X = x;
	this->Pos.Y = y;
}

Size UI::GetSize() {
	return size;
}

void UI::SetSize(float width, float height) {
	this->size.Width = width;
	this->size.Height = height;
}

UI::Speed UI::GetSpeed() {
	return speed;
}

void UI::SetSpeed(float vx, float vy) {
	this->speed.vx = vx;
	this->speed.vy = vy;
}

void UI::JumpUi(float acceleration) {
	speed.vy += acceleration;
	Pos.Y -= speed.vy;
}

UI::UI(){

}

UI::UI(float x, float y, float width, float height){
	SetPos(x, y);
	SetSize(width, height);
}

UI::~UI() {

}