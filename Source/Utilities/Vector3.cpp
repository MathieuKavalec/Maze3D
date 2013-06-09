#include "Vector3.h"

Vector3::Vector3() 
{
	x = y = z = 0;
}

Vector3::Vector3(double a, double b, double c) 
{
	x = a;
	y = b;
	z = c;
}

Vector3::Vector3(const Vector3 &v) 
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector3 Vector3::operator+(const Vector3& v) const
{
	return Vector3((x + v.x), (y + v.y), (z + v.z));
}

Vector3 Vector3::operator-(const Vector3& v) const
{
	return Vector3((x - v.x), (y - v.y), (z - v.z));
}

Vector3 Vector3::operator*(double w) const
{
	return Vector3((x * w), (y * w), (z * w));
}

Vector3 Vector3::operator/(double w) const
{
	return Vector3((x / w), (y / w), (z / w));
}

Vector3 Vector3::operator=(const Vector3& v) 
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

void Vector3::negate() 
{
	x = -x;
	y = -y;
	z = -z;
}

double Vector3::length()  const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

void Vector3::normalize() 
{
	x /= length();
	y /= length();
	z /= length();
}

void Vector3::crossWith(const Vector3& v)
{
    double x1, y1, z1;
 
    x1 = ( v.y * z ) - ( v.z * y );
    y1 = ( v.z * x ) - ( v.x * z );
    z1 = ( v.x * y ) - ( v.y * x );
 
    x = x1;
    y = y1;
    z = z1;
}
 
double Vector3::dotProduct(const Vector3& v) const
{
    return ( x * v.x ) + ( y * v.y ) + ( z * v.z );
}