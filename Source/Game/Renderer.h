#pragma once

#include <chrono>
#include <thread>
#include <memory>
#include "glut.h"

#define RENDER_REFRESH_RATE 5

class Renderer
{
public:
	Renderer();
	~Renderer();

	void start();
	void stop();

private:
	std::unique_ptr<std::thread> thread;
};