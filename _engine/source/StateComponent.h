#ifndef _STATECOMPONENT_H
#define _STATECOMPONENT_H
#include "Component.h"
#include "AnimationComponent.h"
#include "GameObject.h"

namespace engine
{
	enum State
	{
		PLAYABLE_UP,
		PLAYABLE_LEFT,
		PLAYABLE_DOWN,
		PLAYABLE_RIGHT,
		PLAYABLE_UP_WALKING,
		PLAYABLE_LEFT_WALKING,
		PLAYABLE_DOWN_WALKING,
		PLAYABLE_RIGHT_WALKING,
	};


	class StateComponent :
		public ComponentInterface
	{
	public:
		StateComponent() : ComponentInterface("State") {};
		virtual ~StateComponent(void);
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		
		static StateComponent* Factory();
	};
}
#endif
