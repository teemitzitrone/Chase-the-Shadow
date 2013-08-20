#pragma once
#include "Component.h"
class InputComponent :
	public Component
{
public:
	InputComponent(void) { /** **/ };
	virtual ~InputComponent(void) { /** **/ };
	void Input(SDL_Event *input); 
	void Update(GameObject &go);
	void Render(GameObject &go, SDL_Renderer *renderer);
private:
	SDL_Event *_event;
};
