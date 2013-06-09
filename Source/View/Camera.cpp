#include <windows.h>
#include <math.h>
#include "Game.h"
#include "Camera.h"

#define DEG_TO_RAD(a) ((a) * PI / 180.0)
#define PI 3.141592654
#define MAX_PHI 180.0
#define MIN_PHI -170.0
#define VIEWPORT_SCALE_FACTOR 100.0

Camera::Camera()
		: phi(0.0), theta(180.0),
		  moveX(0.0), moveY(0.0), moveZ(0.0)
{
	centerMouse();
	refreshPanSpeed();
}

void Camera::apply()
{
	if (!Game::window().hasFocus())
		return;

	// get mouse movement
	POINT cursor;
	GetCursorPos(&cursor);
	GLdouble rotX = mouseX - cursor.x;
	GLdouble rotY = mouseY - cursor.y;

	centerMouse();

	// rotate camera according to mouse movement
	modifyTheta(rotX / panSpeedX);
	modifyPhi(rotY / panSpeedY);
	adjustAngles();

	// camera movement
	glRotated(-phi, 1.0, 0.0, 0.0);
	glRotated(-theta, 0.0, 1.0, 0.0);
	glTranslated(-moveX, -moveY, -moveZ);
}

void Camera::modifyTheta(GLdouble value)
{
	theta += value;
}

void Camera::modifyPhi(GLdouble value)
{
	phi += value;
}

void Camera::moveSideways(GLdouble value)
{
	GLdouble thetaRad = DEG_TO_RAD(-theta);
	moveX += -value * float(cos(thetaRad));
	moveZ += -value * float(sin(thetaRad));
}

void Camera::moveVertically(GLdouble value)
{
	//@TODO ...
}

void Camera::moveForward(GLdouble value)
{
	moveX += value*float(sin(DEG_TO_RAD(-theta))) ;
	moveZ -= value*float(cos(DEG_TO_RAD(-theta))) ;
	moveY -= value*float(sin(DEG_TO_RAD(-phi))) ;
}

void Camera::refreshPanSpeed()
{
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	panSpeedX = (GLdouble)viewport[2] / VIEWPORT_SCALE_FACTOR;
	panSpeedY = (GLdouble)viewport[3] / VIEWPORT_SCALE_FACTOR;
}

void Camera::adjustAngles()
{
	if (theta > 360.0)
		theta -= 360.0;
	if (theta < -360.0)
		theta += 360.0;
	if (phi > MAX_PHI)
		phi = MAX_PHI;
	if (phi < MIN_PHI)
		phi = MIN_PHI;
}

void Camera::centerMouse()
{
	mouseX = glutGet(GLUT_WINDOW_X) + glutGet(GLUT_WINDOW_WIDTH) / 2.0;
	mouseY = glutGet(GLUT_WINDOW_Y) + glutGet(GLUT_WINDOW_HEIGHT) / 2.0;
	SetCursorPos(mouseX, mouseY);
}
