#include "Player.h"
#include "Novice.h"
#include "Bullet.h"

Player::Player() {

	pos_.x = 640.0f;
	pos_.y = 360.0f;
	speed_.x = 5;
	speed_.y = 5;
	radius_ = 20.0f;

	// Bullet
	for (int i = 0; i < 10; i++) {

		bullet_[i] = new Bullet();
	}
}

Player::~Player() {

	for (int i = 0; i < 10; i++) {

		delete bullet_[i];
	}
}

void Player::Update(char* preKeys, char* keys) {

	if (keys == nullptr) { return; }
	if (preKeys == nullptr) { return; }

	if (isAlive_) {

		// ˆÚ“®ˆ—
		if (keys[DIK_A]) {
			pos_.x -= speed_.x;
		}

		if (keys[DIK_D]) {
			pos_.x += speed_.x;
		}

		if (keys[DIK_S]) {
			pos_.y += speed_.y;
		}

		if (keys[DIK_W]) {
			pos_.y -= speed_.y;
		}

		if (pos_.x < radius_) {

			pos_.x = radius_;
		}

		if (pos_.x > 1280 - radius_) {

			pos_.x = 1280 - radius_;
		}

		// ’e‚Ì”­Ëˆ—
		for (int i = 0; i < 10; i++) {

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

				if (bullet_[i]->GetCount() <= 0) {

					if (!bullet_[i]->GetIsAlive()) {

						bullet_[i]->SetIsAlive(true);
						bullet_[i]->SetPos(pos_);
						bullet_[i]->SetCount(10);
						break;
					}
				}
			}

			bullet_[i]->Update();
		}
	}

	// •œŠˆˆ—
	if (!isAlive_) {

		if (count_ < 0) {

			isAlive_ = true;
			count_ = 50;

		} else {

			count_--;
		}
	}
}

void Player::Draw() {

	if (isAlive_) {

		Novice::DrawEllipse(
			static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, BLUE, kFillModeSolid
		);
	}

	for (int i = 0; i < 10; i++) {

		if (bullet_[i]->GetIsAlive()) {

			bullet_[i]->Draw();
		}
	}
}

void Player::SetPos(Vector2 setPos) {

	this->pos_ = setPos;
}

void Player::SetSpeed(Vector2 setSpeed) {

	this->speed_ = setSpeed;
}

void Player::SetRadius(float setRadius) {

	this->radius_ = setRadius;
}

void Player::SetIsAlive(bool setIsAlive) {

	this->isAlive_ = setIsAlive;
}

void Player::SetCount(int setCount) {

	this->count_ = setCount;
}

void Player::SetBulletPos(int i, Vector2 setPos) {

	bullet_[i]->SetPos(setPos);
}

void Player::SetBulletSpeed(int i, Vector2 setSpeed) {

	bullet_[i]->SetSpeed(setSpeed);
}

void Player::SetBulletRadius(int i, float setRadius) {

	bullet_[i]->SetRadius(setRadius);
}

void Player::SetBulletIsAlive(int i, bool setIsAlive) {

	bullet_[i]->SetIsAlive(setIsAlive);
}


