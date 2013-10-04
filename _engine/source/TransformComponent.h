#ifndef _TRANSFORMCOMPONENT_H
#define _TRANSFORMCOMPONENT_H
#pragma once
#include <SDL.h>
#include "Component.h"
namespace engine
{
	class TransformComponent :
	public Component
	{
	public:
		TransformComponent(void): Component("Transform") {};
		TransformComponent(SDL_Rect position, SDL_Rect rotation, SDL_Rect* scale): _position(position), _rotation(rotation), _scale(scale), Component("Transform") {};
		virtual ~TransformComponent(void) {};
		void Input(SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		SDL_Rect GetPosition();
		SDL_Rect GetRotation();
		SDL_Rect* GetScale();
		static TransformComponent* Factory();
		static TransformComponent* Factory(SDL_Rect);
		static TransformComponent* Factory(SDL_Rect, SDL_Rect);
		static TransformComponent* Factory(SDL_Rect, SDL_Rect, SDL_Rect*);
	private:
		SDL_Rect _position;
		SDL_Rect _rotation;
		SDL_Rect* _scale;
	};
}
#endif