#pragma once
#include "GameObject.h"

class Component
{
public:
	virtual void Input(SDL_Event *input) = 0;
	virtual void Update(GameObject &go) = 0;
	virtual void Render(GameObject &go, SDL_Renderer *renderer) = 0;
};