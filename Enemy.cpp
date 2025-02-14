#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy() {

	pos_.x = 640;
	pos_.y = 200;
	speed_.x = 5;
	speed_.y = 0;
	radius_ = 20;
	isAlive_ = true;
	count_ = 50;
}

Enemy::~Enemy() {
}

void Enemy::Update() {

	// 移動処理
	if (isAlive_) {

		pos_.x += speed_.x;

		if (pos_.x < radius_ || pos_.x > 1280 - radius_) {

			speed_.x *= -1;
		}
	}

	// 復活処理
	if (!isAlive_) {

		if (count_ < 0) {

			isAlive_ = true;
			count_ = 50;

		} else {

			count_--;
		}
	}
}

void Enemy::Draw() {

	if (isAlive_) {

		Novice::DrawEllipse(
			static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, RED, kFillModeSolid
		);
	}
}

void Enemy::SetPos(Vector2 setPos) {

	this->pos_ = setPos;
}

void Enemy::SetSpeed(Vector2 setSpeed) {

	this->speed_ = setSpeed;
}

void Enemy::SetRadius(float setRadius) {

	this->radius_ = setRadius;
}

void Enemy::SetIsAlive(bool isAlive) {

	this->isAlive_ = isAlive;
}

void Enemy::SetCount(int setCount) {

	this->count_ = setCount;
}


