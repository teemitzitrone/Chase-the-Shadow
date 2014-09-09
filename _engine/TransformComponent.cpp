#include "TransformComponent.h"
#include "InputComponent.h"
#include "GameObject.h"
#include <vector>

namespace engine
{
	void TransformComponent::Render(GameObject& gameObject, SDL_Renderer* renderer)
	{
	}

	void TransformComponent::Input(GameObject&, SDL_Event*)
	{
	}

	void TransformComponent::Update(GameObject& gameObject, double)
	{
		Components hits = gameObject.FilterComponent("Input");

		if (hits.size() > 0)
		{
			InputComponent* input = dynamic_cast<InputComponent*> (hits.front().get());

			Direction direction = input->GetDirection();
			
			switch (direction)
			{
			case Direction::up:
				this->_position.y -= (int)this->_speed;
				break;
			case Direction::down:
				this->_position.y += (int)this->_speed;
				break;
			case Direction::left:
				this->_position.x -= (int)this->_speed;
				break;
			case Direction::right:
				this->_position.x += (int)this->_speed;
				break;
			default:
				break;
			}
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

	TransformComponent* TransformComponent::Factory(UnitSpeed speed)
	{
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 0;
		rect.h = 0;

		return new TransformComponent(rect, rect, &rect, speed);
	}

	TransformComponent* TransformComponent::Factory(SDL_Rect position, UnitSpeed speed)
	{
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 0;
		rect.h = 0;

		return new TransformComponent(position, rect, &rect, speed);
	}

	TransformComponent* TransformComponent::Factory(SDL_Rect position, SDL_Rect rotation, UnitSpeed speed)
	{
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 0;
		rect.h = 0;

		return new TransformComponent(position, rotation, &rect, speed);
	}

	TransformComponent* TransformComponent::Factory(SDL_Rect position, SDL_Rect rotation, SDL_Rect* scale, UnitSpeed speed)
	{
		return new TransformComponent(position, rotation, scale, speed);
	}
}
