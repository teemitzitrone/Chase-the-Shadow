#ifndef _CIRCLECOLLIDER_H
#define _CIRCLECOLLIDER_H
#include "Collider.h"

namespace engine
{
	class CircleCollider : public Collider
	{
	public:
		CircleCollider(void) {};
		CircleCollider(const Vector2D position, float radius): Collider(position), _radius(radius) {};
		virtual ~CircleCollider(void) {};
		virtual bool Collision(Collider&);

		void SetRadius(double);
		const float GetRadius() const;

	private:
		float _radius;
	};
}
#endif
