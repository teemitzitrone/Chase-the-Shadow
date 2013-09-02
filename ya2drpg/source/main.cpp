#include <iostream>
#include <SDL.h>
#include "engine\GameLoop.h"
#include "engine\Player.h"
#include "engine\InputComponent.h"
#include "engine\TextureComponent.h"


int main(int argc, char *argv[])
{
	SDL_Window *window = nullptr;
	SDL_Renderer* renderer = nullptr;

	GameObjectManager* manager = new GameObjectManager();
	
	Player *g = new Player;
	g->RegisterComponent(new InputComponent);

	manager->RegisterGameobject(g);

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
		g->RegisterComponent(TextureComponent::Factory("assets/hello.bmp", renderer));
		GameLoop gameloop = GameLoop(renderer, manager);
		gameloop.Run();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}