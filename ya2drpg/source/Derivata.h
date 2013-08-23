#pragma once
#include "engine/GameObject.h"
#include <iostream>

class Derivata :
	public GameObject
{
public:

	Derivata(void)
	{
	}

	virtual ~Derivata(void)
	{
	}
	
	void Input(SDL_Event*) { return;}
	void Update() { 
		//std::cout << "moep" << std::endl;
		return;
	}
	void Render(SDL_Renderer*) { return; }
	void StartUp() { return; }
	void ShutDown() { return; }
	void RegisterComponent(Component*) { return; }
};

