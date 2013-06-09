#pragma once

#include "glut.h"

class Material
{
public:
	Material(GLfloat* Ambiant, GLenum AmbiantFace, GLfloat* Diffuse, GLenum DiffuseFace,
		GLfloat* Specular, GLenum SpecularFace, GLfloat Shininess, GLenum ShininessFace);
	Material(const Material& mat);
	~Material() {}

	void apply() const;

private:
	GLfloat ambiant[4];
	GLenum ambiantFace;

	GLfloat diffuse[4];
	GLenum diffuseFace;

	GLfloat specular[4];
	GLenum specularFace;

	GLfloat shininess;
	GLenum shininessFace;
};