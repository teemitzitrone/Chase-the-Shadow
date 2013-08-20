#pragma once
#include <SDL.h>
#include "Component.h"
#include <vector>

class GameObject
{
public:
	GameObject(void): _alive(true) { /* */ };
	virtual ~GameObject(void) {};
	virtual void StartUp() = 0;
	virtual void Input(SDL_Event *input) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer *renderer) = 0;
	virtual void ShutDown() = 0;
	virtual void RegisterComponent(Component *component) = 0;

protected:
	bool _alive;
	std::vector<Component> _components;
};
