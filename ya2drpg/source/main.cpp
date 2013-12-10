#include <iostream>
#include "world\ScreenManager.h"

int main(int argc, char *argv[])
{
	/// this could be our events triger
	/// auto callback = [](engine::Component trigger, engine::GameObject gameObject) -> void { do some nasty stuff };
	auto func = [](int i) -> double { return 2*i/1.15; };
	double d = func(1);
	std::cout << d << std::endl;

	Game::ScreenManager *screenManager = Game::ScreenManager::GetInstance();

	if (true == screenManager->Init())
	{
		std::string map = Game::ScreenManager::maps.back();
		Game::ScreenManager::maps.pop_back();

		screenManager->LoadMap(map);
		screenManager->Run();
	}

	delete screenManager;

	return 0;
}
