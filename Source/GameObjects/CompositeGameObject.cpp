#include "CompositeGameObject.h"

CompositeGameObject::CompositeGameObject(const std::string& Type, GLuint ID, GLuint Shader)
	: GameObject(Type, ID, Shader)
{
}

CompositeGameObject::~CompositeGameObject()
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
		delete gameObjects[i];
	gameObjects.empty();
}

void CompositeGameObject::render() const
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
		gameObjects[i]->render();
}

void CompositeGameObject::update(GLfloat time)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
		gameObjects[i]->update(time);
}

GameObject* CompositeGameObject::findNext(GLuint ID)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getID() == ID)
			return gameObjects[i];
	}
	return NULL;
}

GameObject* CompositeGameObject::findNext(const std::string& Type)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getType() == Type)
			return gameObjects[i];
	}
	return NULL;
}

GameObject* CompositeGameObject::findNext(const GameObject& object)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (*gameObjects[i] == object)
			return gameObjects[i];
	}
	return NULL;
}

void CompositeGameObject::findAll(GLuint ID, std::vector<GameObject*>& objectsFound)
{
	objectsFound.empty();
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getID() == ID)
			objectsFound.push_back(gameObjects[i]);
	}
}

void CompositeGameObject::findAll(const std::string& Type, std::vector<GameObject*>& objectsFound)
{
	objectsFound.empty();
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getType() == Type)
			objectsFound.push_back(gameObjects[i]);
	}
}

void CompositeGameObject::findAll(const GameObject& object, std::vector<GameObject*>& objectsFound)
{
	objectsFound.empty();
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (*gameObjects[i] == object)
			objectsFound.push_back(gameObjects[i]);
	}
}

void CompositeGameObject::getAll(std::vector<GameObject*>& objects)
{
	objects.empty();
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		objects.push_back(gameObjects[i]);
	}
}

void CompositeGameObject::add(GameObject* newObject) // make sur we don't add the same object twice
{
	gameObjects.push_back(newObject);
}

void CompositeGameObject::add(const std::vector<GameObject*>& objects)
{
	for (unsigned int i = 0; i < objects.size(); ++i)
	{
		gameObjects.push_back(objects[i]);
	}
}

GameObject* CompositeGameObject::removeNext(GLuint ID)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getID() == ID)
		{
			GameObject* objectRemoved = gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
			return objectRemoved;
		}
	}
	return NULL;
}

GameObject* CompositeGameObject::removeNext(const std::string& Type)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getType() == Type)
		{
			GameObject* objectRemoved = gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
			return objectRemoved;
		}
	}
	return NULL;
}

GameObject* CompositeGameObject::removeNext(const GameObject& object)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (*gameObjects[i] == object)
		{
			GameObject* objectRemoved = gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
			return objectRemoved;
		}
	}
	return NULL;
}

bool CompositeGameObject::remove(GameObject* object)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i] == object)
		{
			gameObjects.erase(gameObjects.begin() + i);
			return true;
		}
	}
	return false;
}

std::vector<GameObject*> CompositeGameObject::removeAll(GLuint ID)
{
	std::vector<GameObject*> removedItems;
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getID() == ID)
		{
			removedItems.push_back(gameObjects[i]);
			gameObjects.erase(gameObjects.begin() + i);
		}
	}
	return removedItems;
}

std::vector<GameObject*> CompositeGameObject::removeAll(const std::string& Type)
{
	std::vector<GameObject*> removedItems;
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getType() == Type)
		{
			removedItems.push_back(gameObjects[i]);
			gameObjects.erase(gameObjects.begin() + i);
		}
	}
	return removedItems;
}

std::vector<GameObject*> CompositeGameObject::removeAll(const GameObject& object)
{
	std::vector<GameObject*> removedItems;
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (*gameObjects[i] == object)
		{
			removedItems.push_back(gameObjects[i]);
			gameObjects.erase(gameObjects.begin() + i);
		}
	}
	return removedItems;
}

std::vector<GameObject*> CompositeGameObject::removeAll()
{
	std::vector<GameObject*> removedItems;
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		removedItems.push_back(gameObjects[i]);
	}
	gameObjects.empty();
	return removedItems;
}

void CompositeGameObject::destroyNext(GLuint ID)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getID() == ID)
		{
			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
			return;
		}
	}
}

void CompositeGameObject::destroyNext(const std::string& Type)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getType() == Type)
		{
			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
			return;
		}
	}
}

void CompositeGameObject::destroyNext(const GameObject& object)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (*gameObjects[i] == object)
		{
			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
			return;
		}
	}
}

void CompositeGameObject::destroy(GameObject* object)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i] == object)
		{
			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
			return;
		}
	}
}

void CompositeGameObject::destroyAll(GLuint ID)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getID() == ID)
		{
			delete gameObjects[i];
		}
	}
	gameObjects.empty();
}

void CompositeGameObject::destroyAll(const std::string& Type)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i]->getType() == Type)
		{
			delete gameObjects[i];
		}
	}
	gameObjects.empty();
}

void CompositeGameObject::destroyAll(GameObject& object)
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		if (*gameObjects[i] == object)
		{
			delete gameObjects[i];
		}
	}
	gameObjects.empty();
}

void CompositeGameObject::destroyAll()
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		delete gameObjects[i];
	}
	gameObjects.empty();
}

unsigned int CompositeGameObject::getNumberOfChildren() const
{
	unsigned int nbChildren = 0;
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		nbChildren =  ++nbChildren + gameObjects[i]->getNumberOfChildren();
	}
	return nbChildren;
}