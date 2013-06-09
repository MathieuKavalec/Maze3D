#include <sstream>
#include "Utility.h"

#define PI 3.141592654
#define DEG_TO_RAD(a) ((a) * PI / 180.0)

std::string utility::convertIntToString(int number)
{
	return static_cast<std::ostringstream*>( &(std::ostringstream() << number) )->str();
}

void utility::rotateY(double centerX, double centerZ, double angle, Vector3& point)
{
	point.x -= centerX;
	point.z -= centerZ;

	double nouveauX = point.x * cos(DEG_TO_RAD(angle)) - point.z * sin(DEG_TO_RAD(angle));
	double nouveauZ = point.x * sin(DEG_TO_RAD(angle)) + point.z * cos(DEG_TO_RAD(angle));

	point.x = nouveauX + centerX;
	point.z = nouveauZ + centerZ;
}

void utility::rotateZ(double centerX, double centerY, double angle, Vector3& point)
{
	point.x -= centerX;
	point.y -= centerY;

	double nouveauX = point.x * cos(DEG_TO_RAD(angle)) - point.y * sin(DEG_TO_RAD(angle));
	double nouveauY = point.x * sin(DEG_TO_RAD(angle)) + point.y * cos(DEG_TO_RAD(angle));

	point.x = nouveauX + centerX;
	point.y = nouveauY + centerY;
}

void utility::rotateX(double centerY, double centerZ, double angle, Vector3& point)
{
	point.y -= centerY;
	point.z -= centerZ;

	double nouveauY = point.y * cos(DEG_TO_RAD(angle)) - point.z * sin(DEG_TO_RAD(angle));
	double nouveauZ = point.y * sin(DEG_TO_RAD(angle)) + point.z * cos(DEG_TO_RAD(angle));

	point.y = nouveauY + centerY;
	point.z = nouveauZ + centerZ;
}