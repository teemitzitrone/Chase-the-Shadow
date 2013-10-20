#include <iostream>
#include <SDL.h>
#include "engine\GameLoop.h"
#include <InputComponent.h>
#include <AnimationComponent.h>
#include "engine\MapLoader.h"
#include <StateComponent.h>

int main(int argc, char *argv[])
{
	testJzon();
	SDL_Window *window = nullptr;
	SDL_Renderer* renderer = nullptr;

	GameObjectManager* manager = new GameObjectManager();
	
	SDL_Rect pos;
	pos.x = 34;
	pos.y = 34;
	pos.w = 0;
	pos.h = 0;

	SDL_Rect scale;
	scale.x = 0;
	scale.y = 0;
	scale.w = 64;
	scale.h = 64;

	engine::GameObject player = engine::GameObject::Create(engine::TransformComponent::Factory(pos, pos, &scale));
	player.RegisterComponent(new engine::InputComponent);

	manager->RegisterGameobject(&player);

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	
	window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	} else {
		renderer = SDL_CreateRenderer(
			window, 
			-1, 
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);
	}

	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	} else {
		player.RegisterComponent(engine::StateComponent::Factory());
		player.RegisterComponent(engine::AnimationComponent::Factory("assets/Sprite-Sheet-Prinzessin.png", renderer));
		GameLoop gameloop = GameLoop(renderer, manager);
		gameloop.Run();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}