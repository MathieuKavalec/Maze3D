#pragma once

#include "glut.h"

class Window
{
public:
	Window();
	Window(int ID, GLsizei width, GLsizei height);
	~Window();

	int getID() const;
	int getWidth() const;
	int getHeight() const;

	void setID(int ID);
	void resize(GLsizei width, GLsizei height);
	void focus(int state);
	bool hasFocus() const;

private:
	int ID_;
	int width_;
	int height_;
	bool hasFocus_;
};