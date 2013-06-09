#include "GameLogic.h"
#include "Game.h"
#include "glut.h"

void update(int value)
{
	glutTimerFunc(UPDATE_REFRESH_RATE, update, 0);
	Game::update(value);
	glutPostRedisplay();
}

GameLogic::GameLogic()
{
}

GameLogic::~GameLogic()
{
	stop();
	if (thread != NULL)
		thread.release();
}

void GameLogic::start()
{
	//thread = std::unique_ptr<std::thread>(new std::thread(&update, 1));
	update(UPDATE_REFRESH_RATE);
}

void GameLogic::stop()
{
	if (thread != NULL && thread->joinable())
		thread->join();
}