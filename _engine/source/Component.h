#ifndef _COMPONENT_H
#define _COMPONENT_H
#pragma once
#include <SDL.h>
#include <string>

namespace engine
{
	class GameObject;

	class Component
	{
	public:
		Component(std::string tag): tag(tag) {};
		virtual ~Component(void) {};
		virtual void Input(GameObject&, SDL_Event*) = 0;
		virtual void Update(GameObject&, double) = 0;
		virtual void Render(GameObject&, SDL_Renderer*) = 0;
		std::string tag;
	};
}
#endif