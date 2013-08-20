#pragma once
#include <SDL.h>

#define INPT /*INPUTCLASS*/

class GameObject
{
public:
	GameObject(void): _alive(true) { /* */ };
	virtual ~GameObject(void);
	virtual void StartUp() = 0;
	virtual void Input(INPT) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer *renderer) = 0;
	virtual void ShutDown() = 0;

private:
	bool _alive;
};
