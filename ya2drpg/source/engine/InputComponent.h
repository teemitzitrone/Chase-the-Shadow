#pragma once
#include <SDL.h>
#include "Component.h"
class InputComponent :
	public Component
{
public:
	InputComponent(void) { /** **/ };
	virtual ~InputComponent(void) { /** **/ };
	void Input(SDL_Event*); 
	void Update(GameObject&);
	void Render(GameObject&, SDL_Renderer*);
private:
	SDL_Event *_event;
};
