#include "TransformComponent.h"
#include "InputComponent.h"
#include "GameObject.h"
#include <vector>

namespace engine
{
	void TransformComponent::Render(GameObject& gameObject, SDL_Renderer* renderer)
	{
	}

	void TransformComponent::Input(SDL_Event*)
	{
	}

	void TransformComponent::Update(GameObject& gameObject, double)
	{
		std::vector<Component*> hits = gameObject.FilterComponent("Input");
		InputComponent* input;
		input = dynamic_cast<InputComponent*> (hits.front());

		Direction direction = input->GetDirection();

		switch (direction)
		{
		case Direction::up:
			this->_position.y--;
			break;
		case Direction::down:
			this->_position.y++;
			break;
		case Direction::left:
			this->_position.x--;
			break;
		case Direction::right:
			this->_position.x++;
			break;
		default:
			break;
		}
	}

	SDL_Rect TransformComponent::GetPosition()
	{
		return this->_position;
	}

	SDL_Rect TransformComponent::GetRotation()
	{
		return this->_rotation;
	}

	SDL_Rect* TransformComponent::GetScale()
	{
		return this->_scale;
	}

	TransformComponent* TransformComponent::Factory()
	{
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 0;
		rect.h = 0;

		return new TransformComponent(rect, rect, &rect);
	}

	TransformComponent* TransformComponent::Factory(SDL_Rect position)
	{
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 0;
		rect.h = 0;

		return new TransformComponent(position, rect, &rect);
	}

	TransformComponent* TransformComponent::Factory(SDL_Rect position, SDL_Rect rotation)
	{
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 0;
		rect.h = 0;

		return new TransformComponent(position, rotation, &rect);
	}

	TransformComponent* TransformComponent::Factory(SDL_Rect position, SDL_Rect rotation, SDL_Rect* scale)
	{
		return new TransformComponent(position, rotation, scale);
	}
}
