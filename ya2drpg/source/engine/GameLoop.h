#pragma once

#include <vector>
#include <SDL.h>
#include "GameObject.h"
#include "GameObjectManager.h"

class GameLoop
{
	SDL_Renderer* _renderer;
	GameObjectManager _manager;
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

