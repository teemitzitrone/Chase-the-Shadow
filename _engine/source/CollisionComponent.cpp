#include "CollisionComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include "CircleCollider.h"
#include <vector>

namespace engine
{
	void
	CollisionComponent::Input(GameObject&, SDL_Event*)
	{
	}

	void
	CollisionComponent::Update(GameObject&, double)
	{
	}

	void
	CollisionComponent::Render(GameObject&, SDL_Renderer*)
	{
	}

	const Collider*
	CollisionComponent::GetCollider() const
	{
		return this->_collider;
	}

	CollisionComponent*
	CollisionComponent::Factory(GameObject &gameObject, Collider *collider)
	{
		if (nullptr == collider)
		{
			TransformComponent *transform = static_cast<TransformComponent*>(gameObject.FilterComponent("Transform").front());
			SDL_Rect pos = transform->GetPosition();
			SDL_Rect *scale = transform->GetScale();
			Collider *collider = new CircleCollider(Vector2D(pos.x, pos.y), (scale->h/2));
		}
		
		CollisionComponent *collisionComponent = new CollisionComponent(collider);
		gameObject.RegisterComponent(collisionComponent);

		return collisionComponent;
	}
}
