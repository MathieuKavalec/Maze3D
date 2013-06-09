#pragma once

#include "glut.h"
#include "Ressouce.h"

class Model3D : public Ressouce
{
public:
	Model3D();
	Model3D(GLuint renderList);
};