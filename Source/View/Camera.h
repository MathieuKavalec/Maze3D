#pragma once

#include "glut.h"

class Camera
{
public:
	Camera();
	~Camera(void) {}

	void apply();

	void modifyTheta(GLdouble value);
	void modifyPhi(GLdouble value);

	void moveSideways(GLdouble value);
	void moveVertically(GLdouble value);
	void moveForward(GLdouble value);
	
	void refreshPanSpeed();

private :
	void adjustAngles();
	void centerMouse();

	GLdouble phi, theta;
	GLdouble moveX, moveY, moveZ;
	GLdouble mouseX, mouseY;

	GLdouble panSpeedX, panSpeedY;
};

