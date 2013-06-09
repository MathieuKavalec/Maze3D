#include "Game.h"
#include "InGameKeyboard.h"
#include <windows.h>

void InGameKeyboard::quit()
{
	Game::quit(EXIT_SUCCESS);
}
void InGameKeyboard::keyDownW() {
	Game::player().move[W] = true;
}
void InGameKeyboard::keyDownA() {
	Game::player().move[A] = true;
}
void InGameKeyboard::keyDownS() {
	Game::player().move[S] = true;
}
void InGameKeyboard::keyDownD() {
	Game::player().move[D] = true;
}
void InGameKeyboard::keyUpW() {
	Game::player().move[W] = false;
}
void InGameKeyboard::keyUpA() {
	Game::player().move[A] = false;
}
void InGameKeyboard::keyUpS() {
	Game::player().move[S] = false;
}
void InGameKeyboard::keyUpD() {
	Game::player().move[D] = false;
}