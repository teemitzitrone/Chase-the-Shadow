#ifndef _COLLISIONCOMPONENT_H
#define _COLLISIONCOMPONENT_H
#include "Component.h"
#include "Collider.h"

namespace engine
{
	class CollisionComponent :
		public Component
	{
	public:
		CollisionComponent(void): Component("collider") {};
		CollisionComponent(Collider* collider): Component("collider"), _collider(collider) {};
		virtual ~CollisionComponent(void)
		{
			delete &this->_collider;
		};
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		Collider* GetCollider();

		static CollisionComponent* Factory(GameObject&, Collider* collider = nullptr);

	private:
		Collider* _collider;
	};
}
#endif
