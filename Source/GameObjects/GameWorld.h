#pragma once

#include "CompositeGameObject.h"
#include "glut.h"

#define DEFAULT_GRAVITY 0.2

class GameWorld : public CompositeGameObject
{
public:
	static std::string TYPE_NAME;

	GameWorld(GLuint ID, GLuint Shader);
	GameWorld(GLuint ID, GLuint Shader, GLdouble Gravity);
	GameWorld(const GameWorld& object);
	virtual ~GameWorld();

	virtual void render() const;
	virtual void update(GLfloat time);

	GLdouble getGravity() const;
	void setGravity(GLdouble Gravity);

private:
	GLdouble gravity;
};