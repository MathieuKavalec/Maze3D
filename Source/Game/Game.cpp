#include "Game.h"

Game* Game::instance = 0;

GLuint Game::DEFAULT_ID = 0;
GLuint Game::PLAYER_ID = 1;
GLuint Game::DEFAULT_SHADER = 0;

Game* Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

void Game::freeInstance()
{
	delete instance;
	instance = 0;
}

Game::Game()
	: gameWorld_(DEFAULT_ID, DEFAULT_SHADER), 
	player_(PLAYER_ID, DEFAULT_SHADER)
{
	keyboard_ = new Keyboard();
}

Game::~Game()
{
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
		delete gameObjects[i];
	if (keyboard_ != NULL)
		delete keyboard_;
}

void Game::render()
{
	Game* game = getInstance();
	for (unsigned int i = 0; i < game->gameObjects.size(); ++i)
		game->gameObjects[i]->render();
	game->player_.render();
	game->gameWorld_.render();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	Game::projection().apply();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Game::camera().apply();

	Game::lighting().refresh();

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.1, 0.6, 0.3);
	glTranslated(0.0, 0.0, 15.0);
	glutSolidTeapot(5.0);
	glDisable(GL_COLOR_MATERIAL);

	glutSwapBuffers();
}

void Game::update(GLfloat time)
{
	Game* game = getInstance();
	for (unsigned int i = 0; i < game->gameObjects.size(); ++i)
		game->gameObjects[i]->update(time);
	game->player_.update(time);
	game->gameWorld_.update(time);
}

void Game::resize(GLsizei width, GLsizei height)
{
	Game* game = getInstance();
	game->camera_.refreshPanSpeed();
	game->window_.resize(width, height);
	game->projection_.setAspect((GLdouble)width / (GLdouble)height);
}

void Game::setKeyboard(const Keyboard& keyboardHandler)
{
	delete getInstance()->keyboard_;
	getInstance()->keyboard_ = new Keyboard(keyboardHandler);
}

void Game::windowFocus(int state)
{
	getInstance()->window_.focus(state);
}

void Game::keyUp(unsigned char key, int x, int y)
{
	getInstance()->keyboard_->keyUp(key);
}

void Game::keyDown(unsigned char key, int x, int y)
{
	getInstance()->keyboard_->keyDown(key);
}

void Game::quit(bool success)
{
	Game::freeInstance();
	ExitProcess(success);
}

Lighting& Game::lighting()
{
	return getInstance()->lighting_;
}

Camera& Game::camera()
{
	return getInstance()->camera_;
}

Window& Game::window()
{
	return getInstance()->window_;
}

Projection& Game::projection()
{
	return getInstance()->projection_;
}

GameWorld& Game::gameWorld()
{
	return getInstance()->gameWorld_;
}

Player& Game::player()
{
	return getInstance()->player_;
}

Keyboard& Game::keyboard()
{
	return *getInstance()->keyboard_;
}

Renderer& Game::renderer()
{
	return getInstance()->renderer_;
}

GameLogic& Game::gameLogic()
{
	return getInstance()->gameLogic_;
}