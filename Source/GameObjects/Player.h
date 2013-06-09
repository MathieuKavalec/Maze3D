#pragma once

#include "Vector3.h"

class Character
{
public:
	Character();
	Character(Vector3 Speed);
	~Character();

	Vector3& getSpeed();
	void setSpeed(const Vector3& Speed);

	void draw();
	void update(int gameTime);

private:
	Vector3 speed;
	bool move[4];
};