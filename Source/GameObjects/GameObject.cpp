#include "GameObject.h"

GameObject::GameObject(const std::string& Type, GLuint ID, GLuint Shader)
	: type(Type), id(ID), shader(Shader), visible(true)
{
}

GameObject::GameObject(const GameObject& object)
	: type(object.type), id(object.id), shader(object.shader), visible(object.visible)
{
}

bool GameObject::operator==(const GameObject& object)
{
	return type == object.type && id == object.id;
}

bool GameObject::operator!=(const GameObject& object)
{
	return !(*this == object);
}

GameObject::~GameObject()
{
}

GLuint GameObject::getID() const
{
	return id;
}

GLuint GameObject::getShader() const
{
	return shader;
}

std::string GameObject::getType() const
{
	return type;
}

void GameObject::setShader(GLuint Shader)
{
	shader = Shader;
}