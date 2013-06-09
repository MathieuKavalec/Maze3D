#include "Window.h"

Window::Window()
: ID_(0), width_(0), height_(0), hasFocus_(true)
{
}

Window::Window(int ID, GLsizei width, GLsizei height)
	: ID_(ID), width_(width), height_(height), hasFocus_(true)
{
}

Window::~Window()
{
	if (ID_ != 0)
		glutDestroyWindow(ID_);
}

int Window::getID() const
{
	return ID_;
}

int Window::getWidth() const
{
	return width_;
}

int Window::getHeight() const
{
	return height_;
}

void Window::setID(int ID)
{
	ID_ = ID;
}

void Window::resize(GLsizei width, GLsizei height)
{
	width_ = width;
	height_ = height;
	glViewport(0, 0, width, height);
}

void Window::focus(int state)
{
	if (state == GLUT_LEFT)
		hasFocus_ = false;
	else if (state == GLUT_ENTERED)
		hasFocus_ = true;
}

bool Window::hasFocus() const
{
	return hasFocus_;
}