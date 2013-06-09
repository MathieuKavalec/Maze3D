#pragma once

#include "glut.h"

class Projection
{
public:
	Projection();
	Projection(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
	~Projection() {}

	void apply() const;

	GLdouble getFovy() const;
	GLdouble getAspect() const;
	GLdouble getZNear() const;
	GLdouble getZFar() const;

	void setFovy(GLdouble fovy);
	void setAspect(GLdouble aspect);
	void setZNear(GLdouble zNear);
	void setZFar(GLdouble zFar);

private:
	GLdouble fovy_;
	GLdouble aspect_;
	GLdouble zNear_;
	GLdouble zFar_;
};