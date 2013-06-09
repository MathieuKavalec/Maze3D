#pragma once

#include "glut.h"

class Light
{
public:
	Light(GLenum LIGHT_NAME, const GLfloat* Ambiant, const GLfloat* Diffuse, const GLfloat* Specular, 
		const GLfloat* Position, const GLfloat* SpotDirection, 
		const GLfloat& Exponent, const GLfloat& Cutoff,
		const GLfloat& ConstantAttenuation, const GLfloat& LinearAttenuation, const GLfloat& QuadraticAttenuation);

	~Light() {}

	void refresh() const;

	GLenum LIGHT_GL_ID;
	GLfloat ambiant[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat position[4];
	GLfloat spotDirection[3];
	GLfloat exponent;
	GLfloat cutoff;
	GLfloat constantAttenuation;
	GLfloat linearAttenuation;
	GLfloat quadraticAttenuation;
};