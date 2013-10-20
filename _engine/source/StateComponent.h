#ifndef _STATECOMPONENT_H
#define _STATECOMPONENT_H
#pragma once
#include "Component.h"
#include "AnimationComponent.h"

namespace engine
{
	enum State
	{
		PLAYABLE_UP,
		PLAYABLE_RIGHT,
		PLAYABLE_DOWN,
		PLAYABLE_LEFT,
		PLAYABLE_UP_WALKING,
		PLAYABLE_RIGHT_WALKING,
		PLAYABLE_DOWN_WALKING,
		PLAYABLE_LEFT_WALKING,
	};


	class StateComponent :
		public Component
	{
	private:
		State _currentState;
		AnimationComponent* _animation;

	public:
		StateComponent(AnimationComponent* animation, State state) : _animation(animation), _currentState(state), Component("State") {};
		virtual ~StateComponent(void);
		void Input(SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		
		static StateComponent* Factory(AnimationComponent* animation, State state);
	};
}
#endif
