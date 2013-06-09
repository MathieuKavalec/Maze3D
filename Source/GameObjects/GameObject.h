#pragma once

#include <string>
#include "glut.h"

class GameObject
{
public:
	GameObject(const std::string& Type, GLuint ID, GLuint Shader);
	GameObject(const GameObject& object);
	virtual ~GameObject();

	virtual void render() const {}
	virtual void update(GLfloat time) {}

	GLuint getID() const;
	GLuint getShader() const;
	std::string getType() const;

	void setShader(GLuint Shader);

	bool operator==(const GameObject& object);
	bool operator!=(const GameObject& object);
	
	bool visible;

protected:
	GLuint id;
	std::string type;
	GLuint shader;
};