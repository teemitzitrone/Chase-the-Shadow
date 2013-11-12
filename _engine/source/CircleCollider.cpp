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
		if (radius < 0.0)
		{
			radius = 0.0;
		}

		this->_radius = radius;
	}

	const double
	CircleCollider::GetRadius() const
	{
		return this->_radius;
	}
}
