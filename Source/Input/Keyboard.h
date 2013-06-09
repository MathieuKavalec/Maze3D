#pragma once

#include <map>
#include <functional>

class Keyboard
{
public:
	Keyboard() {}
	~Keyboard() {}

	void registerKeyPressedHandler(unsigned char key, std::function<void()> handler);
	void registerKeyReleasedHandler(unsigned char key, std::function<void()> handler);
	void registerSpecialKeyPressedHandler(unsigned char key, std::function<void()> handler);
	void registerSpecialKeyReleasedHandler(unsigned char key, std::function<void()> handler);

	void keyDown(unsigned char key);
	void keyUp(unsigned char key);
	void specialKeyDown(int key);
	void specialKeyUp(int key);

protected:
	std::map<unsigned char, std::function<void()>> keyPressed;
	std::map<unsigned char, std::function<void()>> keyReleased;
	std::map<int, std::function<void()>> SpecialKeyPressed;
	std::map<int, std::function<void()>> SpecialKeyReleased;
};