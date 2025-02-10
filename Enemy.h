#pragma once
#include "Object.h"

class Enemy : public Object {

public:

	Enemy();
	~Enemy();

	void Update() override;
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
};

