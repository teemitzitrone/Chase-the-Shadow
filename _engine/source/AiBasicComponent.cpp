#include "AiBasicComponent.h"

namespace engine {
	AiBasicComponent::~AiBasicComponent(void)
	{
	}

	void AiBasicComponent::Input(GameObject& gameObject, SDL_Event*)
	{
		if (this->_aggressionTarget == nullptr) {
			this->_direction = (Direction)(int)(abs(sin(rand())) * 4);
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
}