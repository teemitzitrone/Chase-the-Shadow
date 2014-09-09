#ifndef _INPUTCOMPONENT_H
#define _INPUTCOMPONENT_H
#include <SDL.h>
#include "Component.h"

namespace engine
{
	enum Direction
	{
		up, 
		right,
		down,
		left,
		none,
	};

	class InputComponent :
		public ComponentInterface
	{
	public:
		InputComponent(void) : _direction(Direction::none), ComponentInterface("Input") { };
		virtual ~InputComponent(void) { };
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		Direction GetDirection();
	protected:
		Direction _direction;
	};
}
#endif