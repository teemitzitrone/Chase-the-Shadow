#pragma once
#include <SDL.h>
#include "Component.h"

enum Direction
{
	up, 
	right,
	down,
	left,
	none,
};

class InputComponent :
	public Component
{
public:
	InputComponent(void): _direction(Direction::none) { /** **/ };
	virtual ~InputComponent(void) { /** **/ };
	void Input(SDL_Event*); 
	void Update(GameObject&);
	void Render(GameObject&, SDL_Renderer*);
private:
	Direction _direction;
};
