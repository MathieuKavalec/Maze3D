#pragma once

#include "GameObject.h"
#include "Vector3.h"
#include <string>

#define DEFAULT_SPEED 1.5

class Player : public GameObject
{
public:
	static std::string TYPE_NAME;

	Player(GLuint ID, GLuint Shader);
	Player(GLuint ID, GLuint Shader, const Vector3& Speed);
	Player(const Player& object);
	virtual ~Player();

	Vector3& getSpeed();
	void setSpeed(const Vector3& Speed);
	void setSpeed(double x, double y, double z);

	virtual void render() const;
	virtual void update(GLfloat time);

	bool move[4];
private:
	Vector3 speed;
};