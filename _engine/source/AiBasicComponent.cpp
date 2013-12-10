#include "AiBasicComponent.h"
#include <iostream>

#define BLOCK_SIZE 64

namespace engine {
	AiBasicComponent::~AiBasicComponent(void)
	{
	}

	void AiBasicComponent::Input(GameObject& gameObject, SDL_Event*)
	{
		Vector2D origin = this->_getCenter(&gameObject);
		Vector2D target = this->_getCenter(this->_aggressionTarget);

		if (((int)origin.Distance(target) > BLOCK_SIZE * 4 && this->_lockedOnTarget == true)
			|| ((int)origin.Distance(target) > BLOCK_SIZE * 2 && this->_lockedOnTarget == false)) {
			this->_lockedOnTarget = false;
			if (++this->_currentFrame % 64 == 0) {
				this->_direction = (Direction)AiBasicComponent::Roll(Direction::up, Direction::none);
			}
		} else {
			this->_lockedOnTarget = true;
			TransformComponent* targetLocation = (TransformComponent*)this->_aggressionTarget->FilterComponent("Transform").front().get();
			TransformComponent* currentLocation = (TransformComponent*)gameObject.FilterComponent("Transform").front().get();

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

	Vector2D AiBasicComponent::_getCenter(GameObject* gameobject)
	{
		TransformComponent* transfrom = (TransformComponent*)gameobject->FilterComponent("Transform").front().get();

		return Vector2D(
			transfrom->GetPosition().x + (transfrom->GetScale()->w / 2),
			transfrom->GetPosition().y + (transfrom->GetScale()->h / 2)
		);
	}

	int AiBasicComponent::_getDistance(const Vector2D& origin, const Vector2D& target) const
	{
		return (int)origin.Distance(target);
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