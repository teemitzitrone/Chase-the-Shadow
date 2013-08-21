#pragma once
#include <SDL.h>
#include <vector>
#include "Component.h"
class GameObject
{
public:
	GameObject(void): _alive(true) { };
	virtual ~GameObject(void) {};
	virtual void StartUp() = 0;
	virtual void Input(SDL_Event*) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer*) = 0;
	virtual void ShutDown() = 0;
	virtual void RegisterComponent(Component*) = 0;

protected:
	bool _alive;
	std::vector<Component*> _components;
};
