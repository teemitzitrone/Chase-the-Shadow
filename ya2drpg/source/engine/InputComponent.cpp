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
//	switch(this->_direction) {
//		case Direction::up:
//			std::cout << "Up we GO" << std::endl;
//			break;
//		case Direction::right:
//			std::cout << "We are Right" << std::endl;
//			break;
//		case Direction::down:
//			std::cout << "Nothing can bring me Down" << std::endl;
//			break;
//		case Direction::left:
//			std::cout << "Nobody is Left behind" << std::endl;
//			break;
//		case Direction::none:
//			std::cout << "Don't just stand there! Do something" << std::endl;
//			break;
//		default:
//			break;
//	}
}

void InputComponent::Render(GameObject &gameObject, SDL_Renderer *renderer)
{
}

Direction InputComponent::GetDirection()
{
	return this->_direction;
}
