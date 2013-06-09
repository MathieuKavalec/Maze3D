#include "CompositeGameObject.h"

CompositeGameObject::CompositeGameObject(const std::string& Type, GLuint ID, GLuint Shader)
	: GameObject(Type, ID, Shader)
{

}

CompositeGameObject::~CompositeGameObject()
{

}

void CompositeGameObject::render() const
{

}

void CompositeGameObject::update(GLfloat time)
{

}

GameObject* CompositeGameObject::findNext(GLuint ID)
{
	return new GameObject("", 1, 1);
}

GameObject* CompositeGameObject::findNext(const std::string& Type)
{
	return new GameObject("", 1, 1);
}

GameObject* CompositeGameObject::findNext(const GameObject& object)
{
	return new GameObject("", 1, 1);
}

void CompositeGameObject::findAll(GLuint ID, std::vector<GameObject*>& objectsFound)
{

}

void CompositeGameObject::findAll(const std::string& Type, std::vector<GameObject*>& objectsFound)
{

}

void CompositeGameObject::findAll(const GameObject& object, std::vector<GameObject*>& objectsFound)
{

}

void CompositeGameObject::getAll(std::vector<GameObject*>& objects)
{

}

void CompositeGameObject::add(const GameObject* newObject) // make sur we don't add the same object twice
{

}

void CompositeGameObject::add(const std::vector<GameObject*>& objects)
{

}

GameObject* CompositeGameObject::removeNext(GLuint ID)
{
	return new GameObject("", 1, 1);
}

GameObject* CompositeGameObject::removeNext(const std::string& Type)
{
	return new GameObject("", 1, 1);
}

GameObject* CompositeGameObject::removeNext(const GameObject& object)
{
	return new GameObject("", 1, 1);
}

void CompositeGameObject::remove(GameObject* object)
{

}

std::vector<GameObject*> CompositeGameObject::removeAll(GLuint ID)
{
	std::vector<GameObject*> a;
	return a;
}

std::vector<GameObject*> CompositeGameObject::removeAll(const std::string& Type)
{
	std::vector<GameObject*> a;
	return a;
}

std::vector<GameObject*> CompositeGameObject::removeAll(const GameObject& object)
{
	std::vector<GameObject*> a;
	return a;
}

std::vector<GameObject*> CompositeGameObject::removeAll()
{
	std::vector<GameObject*> a;
	return a;
}

void CompositeGameObject::destroyNext(GLuint ID)
{

}

void CompositeGameObject::destroyNext(const std::string& Type)
{

}

void CompositeGameObject::destroyNext(const GameObject& object)
{

}

void CompositeGameObject::destroy(GameObject* object)
{

}

void CompositeGameObject::destroyAll(GLuint ID)
{

}

void CompositeGameObject::destroyAll(const std::string& Type)
{

}

void CompositeGameObject::destroyAll(GameObject& object)
{

}

void CompositeGameObject::destroyAll()
{

}

unsigned int CompositeGameObject::getNumberOfChildren() const
{
	return 0;
}