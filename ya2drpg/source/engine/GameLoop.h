#pragma once

#include <vector>
#include <SDL.h>
#include "GameObject.h"

class GameLoop
{
	SDL_Renderer* _renderer;
	std::vector<GameObject*> _controllers;
	SDL_Surface* _screen;
	bool _done;

private:
	bool _HandleKeystrokes(SDL_Event);
	bool _HandleMouseMotion(SDL_Event);
	bool _HandleEvents(SDL_Event);
	void _HandleFrame();

public:
	GameLoop(SDL_Renderer*);
	virtual ~GameLoop(void);

	void RegisterController(GameObject*);
	void Run();
};

