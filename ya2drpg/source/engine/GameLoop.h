#pragma once

#include <vector>
#include <SDL.h>

#include "GameObject.h"

class GameLoop
{
	std::vector<GameObject*> _controllers;
	SDL_Surface* _screen;
	bool _done;

private:
	bool _HandleKeystrokes(SDL_Event);
	bool _HandleMouseMotion(SDL_Event);
	bool _HandleEvents(SDL_Event);

public:
	GameLoop(void);
	virtual ~GameLoop(void);

	void RegisterController(GameObject*);
	void Run();


};

