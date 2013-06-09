#include "Projection.h"

Projection::Projection()
	: fovy_(60.0), aspect_(1.778), zNear_(0.01), zFar_(1000.0)
{
}

Projection::Projection(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
	: fovy_(fovy), aspect_(aspect), zNear_(zNear), zFar_(zFar)
{
}

void Projection::apply() const
{
	gluPerspective(fovy_, aspect_, zNear_, zFar_);
}

GLdouble Projection::getFovy() const
{
	return fovy_;
}

GLdouble Projection::getAspect() const
{
	return aspect_;
}

GLdouble Projection::getZNear() const
{
	return zNear_;
}

GLdouble Projection::getZFar() const
{
	return zFar_;
}

void Projection::setFovy(GLdouble fovy)
{
	fovy_ = fovy;
}

void Projection::setAspect(GLdouble aspect)
{
	aspect_ = aspect;
}

void Projection::setZNear(GLdouble zNear)
{
	zNear_ = zNear;
}

void Projection::setZFar(GLdouble zFar)
{
	zFar_ = zFar;
}