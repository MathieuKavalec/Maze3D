#pragma once

#include <chrono>
#include <thread>
#include <memory>

#define UPDATE_REFRESH_RATE 1

class GameLogic
{
public:
	GameLogic();
	~GameLogic();

	void start();
	void stop();

private:
	std::unique_ptr<std::thread> thread;
};