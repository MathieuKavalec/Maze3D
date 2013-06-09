#include "Keyboard.h"
#include <cctype>

void Keyboard::keyDown(unsigned char key) {
	key = tolower(key);
	if (keyPressed[key] != NULL)
		keyPressed[key]();
}

void Keyboard::keyUp(unsigned char key) {
	key = tolower(key);
	if (keyReleased[key] != NULL)
		keyReleased[key]();
}

void Keyboard::specialKeyDown(int key) {
	key = tolower(key);
	if (SpecialKeyPressed[key] != NULL)
		SpecialKeyPressed[key]();
}

void Keyboard::specialKeyUp(int key) {
	key = tolower(key);
	if (SpecialKeyReleased[key] != NULL)
		SpecialKeyReleased[key]();
}