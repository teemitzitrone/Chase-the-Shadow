#pragma once
#include "c:\users\mratz\documents\ya2drpg\ya2drpg\source\engine\gameobject.h"
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
	
	void Input() { return;}
	void Update() { 
		std::cout << "moep" << std::endl;
		return;
	}
	void Render(SDL_Renderer*) { return; }
	void StartUp() { return; }
	void ShutDown() { return; }
};

