#pragma once

#include "Vector3.h"
#include <string>

namespace utility
{
	std::string convertIntToString(int number);
	void rotateY(double centerX, double centerZ, double angle, Vector3& point);
	void rotateZ(double centerX, double centerY, double angle, Vector3& point);
	void rotateX(double centerY, double centerZ, double angle, Vector3& point);
}