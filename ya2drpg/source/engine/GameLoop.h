#pragma once

#include <SDL.h>
#include "GameObjectManager.h"
#include "CollisionManager.h"

class GameLoop
{
	SDL_Renderer* _renderer;
	GameObjectManager* _manager;
	bool _done;
	Game::CollisionManager *_collisionManager;

private:
	bool _HandleKeystrokes(SDL_Event);
	bool _HandleMouseMotion(SDL_Event);
	bool _HandleEvents(SDL_Event);
	void _HandleFrame(SDL_Event, double);

public:
	GameLoop(SDL_Renderer*, GameObjectManager*, Game::CollisionManager*);
	virtual ~GameLoop(void);

	void RegisterController(engine::GameObject*);
	void Run();
};

