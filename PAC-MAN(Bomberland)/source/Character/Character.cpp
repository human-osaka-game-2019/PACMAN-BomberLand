#include "../Main.h"
#include "Character.h"

Anime::Anime():frame(0),change_frame(4),is_loop(true),UV(0.0f,0.0f) {

}

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

void PLAYER::SetSpeed(float speed) {
	this->speed = speed;
}

void PLAYER::SetDirection(PLAYER::DIRECTION direction) {
	this->direction = direction;
}

int PLAYER::GetLiveCount() {
	return this->LiveCount;
}

void PLAYER::SetLiveCount(int LiveCount) {
	this->LiveCount = LiveCount;
}

void PLAYER::Animation(std::string TextureName) {
	if (anime.frame > anime.change_frame) {
		anime.UV.X += Texture_WU;
		if (anime.UV.X >= Texture_WU * 3) {
			anime.UV.X == 0.0f;
		}
		anime.frame = 0;
	}
	dx.DrawEx(pos.X, pos.Y, 0, size.Width, size.Height, direction, 1.0f, false, TextureName, anime.UV.X, anime.UV.Y, Texture_WU, Texture_HV);
	anime.frame++;
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

PLAYER::PLAYER():LiveCount(3),direction(RIGHT){
	SetPos(160, 140);
	SetSize(40, 40);
}

PLAYER::~PLAYER() {

}

Vec2 COOKIE::GetPos() {
	return this->CenterPos;
}

void COOKIE::SetPos(float x,float y) {
	this->CenterPos.X = x;
	this->CenterPos.Y = y;
}

COOKIE::COOKIE():size(30,30),is_dead(false) {

}