#pragma once
#include "GameObject.h"
#include "TransformComponent.h"

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

	static Player* Factory()
	{
		Player *player = new Player();
		player->RegisterComponent(TransformComponent::Factory());

		return player;
	}
};
