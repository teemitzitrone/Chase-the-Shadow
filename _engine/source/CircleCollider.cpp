#include "CircleCollider.h"

namespace engine
{
	bool
	CircleCollider::Collision(Collider& collider)
	{
		CircleCollider* circle = dynamic_cast<CircleCollider*>(&collider);

		if (circle != nullptr)
		{
			float distance = this->GetPosition().Distance(circle->GetPosition());

			return (distance <= (this->GetRadius() + circle->GetRadius()));
		}
		else
		{
			return false;
		}
	}

	void
	CircleCollider::SetRadius(double radius)
	{
		this->_radius = radius;
	}

	const float
	CircleCollider::GetRadius() const
	{
		return this->_radius;
	}
}
