#include "GameWorld.h"

std::string GameWorld::TYPE_NAME = "GAMEWORLD";

GameWorld::GameWorld(GLuint ID, GLuint Shader)
	: CompositeGameObject(TYPE_NAME, ID, Shader), gravity(DEFAULT_GRAVITY)
{
}

GameWorld::GameWorld(GLuint ID, GLuint Shader, GLdouble Gravity)
	: CompositeGameObject(TYPE_NAME, ID, Shader), gravity(Gravity)
{
}

GameWorld::GameWorld(const GameWorld& object)
	: CompositeGameObject(object), gravity(object.gravity)
{
}

GameWorld::~GameWorld()
{
}

void GameWorld::render() const
{

}

void GameWorld::update(GLfloat time)
{

}

GLdouble GameWorld::getGravity() const
{
	return gravity;
}

void GameWorld::setGravity(GLdouble Gravity)
{
	gravity = Gravity;
}