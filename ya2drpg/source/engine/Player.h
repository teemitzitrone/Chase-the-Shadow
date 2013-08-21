#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player(void) {};
	virtual ~Player(void) {};
	void StartUp();
	void Input(SDL_Event*);
	void Update();
	void Render(SDL_Renderer*);
	void ShutDown();
	void RegisterComponent(Component*);
};
