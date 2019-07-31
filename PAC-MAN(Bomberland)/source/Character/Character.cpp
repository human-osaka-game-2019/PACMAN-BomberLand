#include "../Main.h"
#include "Character.h"

Anime::Anime():frame(0),change_frame(4),is_loop(true),UV(0.0f,0.0f) {

}

Vec2 PLAYER::GetPos() {
	return this->pos;
}

void PLAYER::SetPos(float x, float y) {
	pos.X = x;
	pos.Y = y;
}

Vec2 PLAYER::GetCenterPos() {
	return this->CenterPos;
}

void PLAYER::SetCenterPos(float CenterX, float CenterY) {
	this->CenterPos.X = CenterX;
	this->CenterPos.Y = CenterY;
}

Size PLAYER::GetSize() {
	return this->size;
}

void PLAYER::SetSize(float width, float height) {
	size.Width = width;
	size.Height = height;
}

float PLAYER::GetSpeed() {
	return this->speed;
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

PLAYER::PLAYER():LiveCount(3),direction(RIGHT),CenterPos(pos.X + size.Width / 2, pos.Y + size.Height / 2) {
	SetPos(50, 50);
	SetSize(40, 40);
}

PLAYER::~PLAYER() {

}

Vec2 ENEMY_BASE::GetPos() {
	return this->pos;
}

Vec2 COOKIE::GetPos() {
	return this->CenterPos;
}

void ENEMY_BASE::SetPos(float x, float y) {
	this->pos.X = x;
	this->pos.Y = y;
}

void COOKIE::SetPos(float x,float y) {
	this->CenterPos.X = x;
	this->CenterPos.Y = y;
}

Size ENEMY_BASE::GetSize() {
	return this->size;
}

COOKIE::COOKIE():size(30,30),is_dead(false) {

}
void ENEMY_BASE::SetSize(float width, float height) {
	this->size.Width = width;
	this->size.Height = height;
}
