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
	CollisionComponent::Update(GameObject& gameObject, double)
	{
		TransformComponent *transform = static_cast<TransformComponent*>(gameObject.FilterComponent("Transform").front().get());
		SDL_Rect pos = transform->GetPosition();

		this->_collider->SetPosition(Vector2D((float)pos.x, (float)pos.y));
	}

	void
	CollisionComponent::Render(GameObject&, SDL_Renderer*)
	{
	}

	Collider*
	CollisionComponent::GetCollider()
	{
		return this->_collider;
	}

	CollisionComponent*
	CollisionComponent::Factory(GameObject &gameObject, Collider *collider)
	{
		if (nullptr == collider)
		{
			TransformComponent *transform = static_cast<TransformComponent*>(gameObject.FilterComponent("Transform").front().get());
			SDL_Rect pos = transform->GetPosition();
			SDL_Rect *scale = transform->GetScale();
			collider = new CircleCollider(Vector2D((float)pos.x, (float)pos.y), (scale->h/2));
		}

		CollisionComponent *collisionComponent = new CollisionComponent(collider);
		gameObject.RegisterComponent(Component(new CollisionComponent(collider)));

		return collisionComponent;
	}
}
