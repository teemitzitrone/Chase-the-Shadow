#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"
#include "TransformComponent.h"

namespace engine
{
	class GameObject
	{
	public:
		virtual ~GameObject(void) {};
		void StartUp();
		void Input(SDL_Event*);
		void Update(double);
		void Render(SDL_Renderer*);
		void ShutDown();
		void RegisterComponent(Component*);
		std::vector<Component*> FilterComponent(std::string);
		static GameObject Create(TransformComponent* component = nullptr);

	private:
		bool _alive;
		std::vector<Component*> _components;

		GameObject(void): _alive(true) { };
	};
}
#endif