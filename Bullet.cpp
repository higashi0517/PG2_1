#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {

	pos_.x = 0;
	pos_.y = 0;
	speed_.x = 0;
	speed_.y = -5;
	radius_ = 8;
	isAlive_ = false;
	count_ = 10;
}

Bullet::~Bullet() {
}

void Bullet::Update() {

	// 移動処理
	if (isAlive_) {

		pos_.y += speed_.y;

		if (pos_.y < 0) {

			isAlive_ = false;
		}
	}

	// 復活処理
	if (count_ > 0) {

		count_--;
	}
}

void Bullet::Draw() {

	Novice::DrawEllipse(
		static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, GREEN, kFillModeSolid
	);
}

void Bullet::SetPos(Vector2 setPos) {

	this->pos_ = setPos;
}

void Bullet::SetSpeed(Vector2 setSpeed) {

	this->speed_ = setSpeed;
}

void Bullet::SetRadius(float setRadius) {

	this->radius_ = setRadius;
}

void Bullet::SetIsAlive(bool setIsAlive) {

	this->isAlive_ = setIsAlive;
}

void Bullet::SetCount(int setCount) {

	this->count_ = setCount;
}