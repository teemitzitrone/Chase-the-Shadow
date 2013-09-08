#pragma once
#include <SDL.h>
#include <string>
class GameObject;

class Component
{
public:
	Component(std::string tag): tag(tag) {};
	virtual ~Component(void) {};
	virtual void Input(SDL_Event*) = 0;
	virtual void Update(GameObject&) = 0;
	virtual void Render(GameObject&, SDL_Renderer*) = 0;
	std::string tag;
};
