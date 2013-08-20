#pragma once
#include "GameObject.h"
#include "Component.h"

class Player :
	public GameObject
{
public:
	Player(void);
	virtual ~Player(void);
	void StartUp();
	void Input(SDL_Event *input);
	void Update();
	void Render(SDL_Renderer *renderer);
	void ShutDown() = 0;
	void RegisterComponent(Component *component);
};
