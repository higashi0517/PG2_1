#include "Object.h"

Object::Object() {

	pos_.x = 0;
	pos_.y = 0;
	speed_.x = 0;
	speed_.y = 0;
	radius_ = 0;
	isAlive_ = false;
	count_ = 0;
}

Object::~Object() {
}

void Object::Update() {
}

void Object::Draw() {
}
