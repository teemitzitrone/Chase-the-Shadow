#include <iostream>
#include "world\ScreenManager.h"

int main(int argc, char *argv[])
{
	/// this could be our events triger
	/// auto callback = [](engine::Component trigger, engine::GameObject gameObject) -> void { do some nasty stuff };
	auto func = [](int i) -> double { return 2*i/1.15; };
	double d = func(1);
	std::cout << d << std::endl;

	Game::ScreenManager screenManager = Game::ScreenManager();

	if (true == screenManager.Init())
	{
		screenManager.LoadMap("resources/maps/prolog.json");
		screenManager.Run();
	}

	return 0;
}
