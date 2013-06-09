#include "Player.h"

#define DEFAULT_SPEED 1.5

Character::Character()
	: speed(DEFAULT_SPEED, DEFAULT_SPEED, DEFAULT_SPEED)
{
	for (int i = 0; i < 4; ++i)
		move[i] = false;
}
Character::Character(Vector3 Speed)
	: speed(Speed)
{
	for (int i = 0; i < 4; ++i)
		move[i] = false;
}

Character::~Character()
{
}

Vector3& Character::getSpeed()
{
	return speed;
}

void Character::setSpeed(const Vector3& Speed)
{
	speed = Speed;
}

void Character::draw()
{

}

void Character::update(int gameTime)
{

}