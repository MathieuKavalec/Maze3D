#include "Lighting.h"

void Lighting::addLight(const Light& light)
{
	lights.push_back(light);
}

void Lighting::refresh() const
{
	for (unsigned int i = 0; i < lights.size(); ++i)
	{
		lights[i].refresh();
	}
}

unsigned int Lighting::getNumberOfLights() const
{
	return lights.size();
}

std::vector<Light>& Lighting::getLights()
{
	return lights;
}
