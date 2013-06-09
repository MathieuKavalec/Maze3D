#include "Renderer.h"

/*#include <iostream>
int previousTime = 0;*/
void render(int value)
{
	/*glutTimerFunc(RENDER_REFRESH_RATE, render, 0);
	int time = glutGet(GLUT_ELAPSED_TIME);
	glutPostRedisplay();
	std::cout << time - previousTime << std::endl;
	previousTime = time;*/
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	stop();
	if (thread != NULL)
		thread.release();
}

void Renderer::start()
{
	//thread = std::unique_ptr<std::thread>(new std::thread(&render, 1));
	render(0);
}

void Renderer::stop()
{
	if (thread != NULL && thread->joinable())
		thread->join();
}