#pragma once
#include <SDL.h>
class GameObject;

class Component
{
public:
	virtual void Input(SDL_Event*) = 0;
	virtual void Update(GameObject&) = 0;
	virtual void Render(GameObject&, SDL_Renderer*) = 0;
};