#include "AiBasicComponent.h"
#include <iostream>

namespace engine {
	AiBasicComponent::~AiBasicComponent(void)
	{
	}

	void AiBasicComponent::Input(GameObject& gameObject, SDL_Event*)
	{
		if (this->_aggressionTarget == nullptr) {
			this->_direction = (Direction)AiBasicComponent::Roll(Direction::up, Direction::none);
		} else {
			TransformComponent* targetLocation = (TransformComponent*)this->_aggressionTarget->FilterComponent("Transform").front();
			TransformComponent* currentLocation = (TransformComponent*)gameObject.FilterComponent("Transform").front();

			if (targetLocation->GetPosition().x < currentLocation->GetPosition().x) {
				this->_direction = Direction::left;
			} else if (targetLocation->GetPosition().x > currentLocation->GetPosition().x) {
				this->_direction = Direction::right;
			} else if (targetLocation->GetPosition().y < currentLocation->GetPosition().y) {
				this->_direction = Direction::up;
			} else if (targetLocation->GetPosition().y > currentLocation->GetPosition().y) {
				this->_direction = Direction::down;
			} else {
				this->_direction = Direction::none;
			}
		}
	}

	void AiBasicComponent::Update(GameObject&, double)
	{
	}

	void AiBasicComponent::Render(GameObject&, SDL_Renderer*)
	{
	}

	int AiBasicComponent::Roll(int min, int max, bool include)
	{
		if (include)
		{
			max++;
		}

		double seed = rand()/static_cast<double>(RAND_MAX);
		int dice = min + static_cast<int>(seed * (max - min));

		return dice;
	}
}