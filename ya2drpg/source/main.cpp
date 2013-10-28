#include <iostream>
#include <SDL.h>
#include "engine\GameLoop.h"
#include <InputComponent.h>
#include <AnimationComponent.h>
#include "engine\MapLoader.h"
#include <StateComponent.h>
#include <AiBasicComponent.h>

int main(int argc, char *argv[])
{
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

	SDL_Rect pos_enemy;
	pos_enemy.x = 320;
	pos_enemy.y = 320;
	pos_enemy.w = 0;
	pos_enemy.h = 0;

	SDL_Rect scale_enemy;
	scale_enemy.x = 0;
	scale_enemy.y = 0;
	scale_enemy.w = 64;
	scale_enemy.h = 64;

	engine::GameObject player = engine::GameObject::Create(engine::TransformComponent::Factory(pos, pos, &scale));
	player.RegisterComponent(new engine::InputComponent);
	player.RegisterComponent(engine::StateComponent::Factory());
	
	engine::GameObject enemy = engine::GameObject::Create(engine::TransformComponent::Factory(pos_enemy, pos_enemy, &scale_enemy, engine::UnitSpeed::Slow));
	enemy.RegisterComponent(new engine::AiBasicComponent(&player));
	enemy.RegisterComponent(engine::StateComponent::Factory());
	
	manager->RegisterGameobject(&player);
	manager->RegisterGameobject(&enemy);

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
		//player.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/princess.png", renderer));
		player.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/princess_sparkle.png", renderer));
		//player.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/hero.png", renderer));
		//player.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/villain.png", renderer));
		enemy.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/spider.png", renderer));

		Game::MapLoader loader =  Game::MapLoader();
		loader.LoadMap("resources/dorf_map.json", (*manager));

		GameLoop gameloop = GameLoop(renderer, manager);
		gameloop.Run();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}