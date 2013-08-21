#pragma once

#include <vector>
#include <SDL.h>
#include "GameObjectManager.h"
class GameLoop
{
	SDL_Renderer* _renderer;
	GameObjectManager* _manager;
	bool _done;

private:
	bool _HandleKeystrokes(SDL_Event);
	bool _HandleMouseMotion(SDL_Event);
	bool _HandleEvents(SDL_Event);
	void _HandleFrame(SDL_Event);

public:
	GameLoop(SDL_Renderer*, GameObjectManager*);
	virtual ~GameLoop(void);

	void RegisterController(GameObject*);
	void Run();
};

