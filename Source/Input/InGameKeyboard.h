#pragma once

#include "Keyboard.h"

#ifndef moveKeys
#define moveKeys
enum moveKeys {W, A, S, D};
#endif

class InGameKeyboard : public Keyboard
{
public:
	InGameKeyboard()
	{
		keyPressed[27] = std::bind(&InGameKeyboard::quit, this);
		keyPressed['q'] = std::bind(&InGameKeyboard::quit, this);
		keyPressed['w'] = std::bind(&InGameKeyboard::keyDownW, this);
		keyPressed['a'] = std::bind(&InGameKeyboard::keyDownA, this);
		keyPressed['s'] = std::bind(&InGameKeyboard::keyDownS, this);
		keyPressed['d'] = std::bind(&InGameKeyboard::keyDownD, this);
		keyReleased['w'] = std::bind(&InGameKeyboard::keyUpW, this);
		keyReleased['a'] = std::bind(&InGameKeyboard::keyUpA, this);
		keyReleased['s'] = std::bind(&InGameKeyboard::keyUpS, this);
		keyReleased['d'] = std::bind(&InGameKeyboard::keyUpD, this);
	}

	~InGameKeyboard() {};

private:
	void quit();
	void keyDownW();
	void keyDownA();
	void keyDownS();
	void keyDownD();
	void keyUpW();
	void keyUpA();
	void keyUpS();
	void keyUpD();
};