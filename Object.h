#pragma once
#include "Struct.h"

class Object{

protected:

	Object();
	virtual ~Object();

	virtual void Update();
	virtual void Draw();

	Vector2 pos_;
	Vector2 speed_;
	float radius_;
	bool isAlive_;
	int count_;
};

