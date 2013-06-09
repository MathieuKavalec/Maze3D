#pragma once

#include <vector>
#include <string>
#include "Shaders.h"
#include "GameObject.h"
#include "glut.h"

class CompositeGameObject : public GameObject
{
public:
	CompositeGameObject(const std::string& Type, GLuint ID, GLuint Shader);
	virtual ~CompositeGameObject();

	virtual void render() const;
	virtual void update(GLfloat time);

	GameObject* findNext(GLuint ID);
	GameObject* findNext(const std::string& Type);
	GameObject* findNext(const GameObject& object);
	void findAll(GLuint ID, std::vector<GameObject*>& objectsFound);
	void findAll(const std::string& Type, std::vector<GameObject*>& objectsFound);
	void findAll(const GameObject& object, std::vector<GameObject*>& objectsFound);
	void getAll(std::vector<GameObject*>& objects);

	void add(const GameObject* newObject);
	void add(const std::vector<GameObject*>& objects);

	GameObject* removeNext(GLuint ID);
	GameObject* removeNext(const std::string& Type);
	GameObject* removeNext(const GameObject& object);
	void remove(GameObject* object);
	std::vector<GameObject*> removeAll(GLuint ID);
	std::vector<GameObject*> removeAll(const std::string& Type);
	std::vector<GameObject*> removeAll(const GameObject& object);
	std::vector<GameObject*> removeAll();

	void destroyNext(GLuint ID);
	void destroyNext(const std::string& Type);
	void destroyNext(const GameObject& object);
	void destroy(GameObject* object);
	void destroyAll(GLuint ID);
	void destroyAll(const std::string& Type);
	void destroyAll(GameObject& object);
	void destroyAll();

	unsigned int getNumberOfChildren() const;

protected:
	std::vector<GameObject*> gameObjects;
};