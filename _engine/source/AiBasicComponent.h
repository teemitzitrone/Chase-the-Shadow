#ifndef _AIBASICCOMPONENT_H
#define _AIBASICCOMPONENT_H
#pragma once
#include "Component.h"
#include "InputComponent.h"
#include "GameObject.h"

namespace engine {

	class AiBasicComponent : 
		public InputComponent
	{
	protected:
		GameObject* _aggressionTarget;

	public:
		AiBasicComponent(GameObject* agressionTarget): _aggressionTarget(agressionTarget) {};
		virtual ~AiBasicComponent(void);
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
	};
}
#endif