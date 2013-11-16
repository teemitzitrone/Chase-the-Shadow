#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#include <SDL.h>
#include <vector>
#include "Vector2D.h"
#include "TransformComponent.h"

namespace engine
{
	class GameObject
	{
	public:
		bool alive;
		std::string tag;

		virtual ~GameObject(void) {};
		void Input(SDL_Event*);
		void Update(double);
		void Render(SDL_Renderer*);
		void RegisterComponent(Component*);
		std::vector<Component*> FilterComponent(std::string);
		static GameObject Create(TransformComponent* component = nullptr);

	private:
		std::vector<Component*> _components;

		GameObject(void): alive(true) {};
	};
}
#endif