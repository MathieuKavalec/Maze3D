#pragma once

#include <vector>
#include "glut.h"

#include "Light.h"

class Lighting
{
public:
	Lighting() {}
	~Lighting() {}

	void addLight(const Light& light);

	void refresh() const;

	unsigned int getNumberOfLights() const;

	std::vector<Light>& getLights();

private:
	std::vector<Light> lights;
};