#include "InputComponent.h"
#include <iostream>

void InputComponent::Input(SDL_Event *event)
{
	this->_event = event;
}

void InputComponent::Update(GameObject &gameObject)
{
	if ((*this->_event).key.keysym.sym == SDLK_w)
	{
		std::cout << "Up we GO" << std::endl;
	}
}

void InputComponent::Render(GameObject &gameObject, SDL_Renderer *renderer)
{
	std::cout << "Draw Call Player" << std::endl;
}