#ifndef _AIBASICCOMPONENT_H
#define _AIBASICCOMPONENT_H
#include "Component.h"
#include "InputComponent.h"
#include "GameObject.h"

namespace engine {

	class AiBasicComponent : 
		public InputComponent
	{
	protected:
		int _currentFrame;
		GameObject* _aggressionTarget;

	public:
		AiBasicComponent(GameObject* agressionTarget): _aggressionTarget(agressionTarget) {};
		virtual ~AiBasicComponent(void);
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		static int Roll(int min = 0, int max = 4, bool include = true);
	};
}
#endif