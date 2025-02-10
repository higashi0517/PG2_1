#pragma once
#include "Object.h"
#include "Bullet.h"

class Player : public Object {

public:

	Player();
	~Player();

	void Update(char* preKeys, char* keys);
	void Draw() override;

	Vector2 GetPos() { return pos_; }
	Vector2 GetSpeed() { return speed_; }
	float GetRadius() { return radius_; }
	bool GetIsAlive() { return isAlive_; }
	int GetCount() { return count_; }

	void SetPos(Vector2 setPos);
	void SetSpeed(Vector2 setSpeed);
	void SetRadius(float setRadius);
	void SetIsAlive(bool setIsAlive);
	void SetCount(int setCount);

	// Bullet
	Bullet* bullet_[10];

	Vector2 GetBulletPos(int i) { return bullet_[i]->GetPos(); }
	Vector2 GetBulletSpeed(int i) { return bullet_[i]->GetSpeed(); }
	float GetBulletRadius(int i) { return bullet_[i]->GetRadius(); }
	bool GetBulletIsAlive(int i) { return bullet_[i]->GetIsAlive(); }

	void SetBulletPos(int i, Vector2 setPos);
	void SetBulletSpeed(int i, Vector2 setSpeed);
	void SetBulletRadius(int i, float setRadius);
	void SetBulletIsAlive(int i, bool setIsAlive);
};

