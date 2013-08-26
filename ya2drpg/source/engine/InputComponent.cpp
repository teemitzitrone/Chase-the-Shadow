#include "InputComponent.h"
#include <iostream>

void InputComponent::Input(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_KEYDOWN:
		switch (event->key.keysym.sym)
		{
		case SDLK_w:
			this->_direction = Direction::up;
			break;
		case SDLK_a:
			this->_direction = Direction::left;
			break;
		case SDLK_s:
			this->_direction = Direction::down;
			break;
		case SDLK_d:
			this->_direction = Direction::right;
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		if (event->key.keysym.sym == SDLK_w
			|| event->key.keysym.sym == SDLK_a
			|| event->key.keysym.sym == SDLK_s
			|| event->key.keysym.sym == SDLK_d)
		{
			this->_direction = Direction::none;
		}
		break;
	default:
		break;
	}
}

void InputComponent::Update(GameObject &gameObject)
{
	if (this->_direction == Direction::up)
	{
		std::cout << "Up we GO" << std::endl;
	}
}

void InputComponent::Render(GameObject &gameObject, SDL_Renderer *renderer)
{
}