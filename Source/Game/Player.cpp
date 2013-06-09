#include "Game.h"
#include "Player.h"

#ifndef moveKeys
#define moveKeys
enum moveKeys {W, A, S, D};
#endif

std::string Player::TYPE_NAME = "PLAYER";

Player::Player(GLuint ID, GLuint Shader)
	: GameObject(TYPE_NAME, ID, Shader), speed(DEFAULT_SPEED, DEFAULT_SPEED, DEFAULT_SPEED)
{
	for (int i = 0; i < 4; ++i)
		move[i] = false;
}
Player::Player(GLuint ID, GLuint Shader, const Vector3& Speed)
	: GameObject(TYPE_NAME, ID, Shader), speed(Speed)
{
	for (int i = 0; i < 4; ++i)
		move[i] = false;
}

Player::Player(const Player& object)
	: GameObject(object), speed(object.speed)
{
	for (int i = 0; i < 4; ++i)
		move[i] = false;
}

Player::~Player()
{
}

Vector3& Player::getSpeed()
{
	return speed;
}

void Player::setSpeed(const Vector3& Speed)
{
	speed = Speed;
}

void Player::setSpeed(double x, double y, double z)
{
	speed.x = x;
	speed.y = y;
	speed.z = z;
}

void Player::render() const
{

}

void Player::update(GLfloat time)
{
	if (move[W])
		Game::camera().moveForward(speed.z);
	if (move[A])
		Game::camera().moveSideways(speed.x);
	if (move[S])
		Game::camera().moveForward(-speed.z);
	if (move[D])
		Game::camera().moveSideways(-speed.x);
}