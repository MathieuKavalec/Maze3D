#pragma once

#include <math.h>

/*
The Vector3 class: represents a 3 dimensional vector. Only has 3 variables: x, y, and z for displacement.
*/
class Vector3 
{
public:
	double x, y, z;

	/*Constructors:
	Vector3 v: x, y, and z are all set to 0.
	Vector3 v2(1, 2, 3): x, y, and z are set to 1, 2, and 3, respectivly.
	Vector3 v3(Vector3D v4): v3.x, v3.y, and v3.z are all set to v4.x, v4.y, and v4.z, respectivly.
	*/
	Vector3();
	Vector3(double a, double b, double c);
	Vector3(const Vector3 &v);

	/*Operator overloadings:
	Vector3 operator+(Vector v): x, y, and z are added to v.x, v.y, and v.z, respectivly.
	Vector3 operator-(Vector3D v): x, y, and z are subtracted from v.x, v.y, and v.z, respectivly.
	Vector3 operator*(double w): x, y, and z are all multiplied by w.
	Vector3 operator/(double w): x, y, and z are all divided by w.
	Vector3 operator=(Vector3D v): this vector is set to v.
	*/
	Vector3 operator+(const Vector3& v) const;
	Vector3 operator-(const Vector3& v) const;
	Vector3 operator*(double w) const;
	Vector3 operator/(double w) const;
	Vector3 operator=(const Vector3& v);

	/*Other functions:
	void negate(): negate the vector - x, y, and z are set to -x, -y, and -z, respectivly
	double length(): returns the length of the vector.
	void normalize(): normalize the vector, vector / length of vector
	crossWith(): cross product with another vector
	dotProduct(): dot product with another vector
	*/
	void negate();
	double length() const;
	void normalize();
	void crossWith(const Vector3& v);
	double dotProduct(const Vector3& v) const;
};