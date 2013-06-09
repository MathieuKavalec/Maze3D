#pragma once

#include "glew.h"
#include <vector>
#include <windows.h>
#include "GameLogic.h"
#include "Lighting.h"
#include "Camera.h"
#include "Window.h"
#include "Projection.h"
#include "GameWorld.h"
#include "Player.h"
#include "Keyboard.h"
#include "InGameKeyboard.h"
#include "GameObject.h"
#include "Renderer.h"

class Game
{
public:
	static Game* getInstance();
	static void freeInstance();

	static Lighting& lighting();
	static Camera& camera();
	static Window& window();
	static Projection& projection();
	static GameWorld& gameWorld();
	static Player& player();
	static Keyboard& keyboard();
	static Renderer& renderer();
	static GameLogic& gameLogic();

	static void render();
	static void update(GLfloat time);

	static void setKeyboard(const Keyboard& keyboardHandler);
	static void resize(GLsizei width, GLsizei height);
	static void windowFocus(int state);
	static void keyUp(unsigned char key, int x, int y);
	static void keyDown(unsigned char key, int x, int y);
	static void quit(bool success);

private:
	Game();
	~Game();
	Game(const Game&);
	Game& operator=(const Game&);
	static Game* instance;

	Lighting lighting_;
	Camera camera_;
	Window window_;
	Projection projection_;
	GameWorld gameWorld_;
	Player player_;
	Keyboard* keyboard_;
	Renderer renderer_;
	GameLogic gameLogic_;

	static GLuint DEFAULT_ID;
	static GLuint PLAYER_ID;
	static GLuint DEFAULT_SHADER;

	std::vector<GameObject*> gameObjects;
};