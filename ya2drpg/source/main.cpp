﻿#include <iostream>
#include <SDL.h>
#include <_engine.h>
#include "engine\GameLoop.h"
#include "engine\MapLoader.h"
#include <map>

int main(int argc, char *argv[])
{
	/// this could be our events triger
	/// auto callback = [](engine::Component trigger, engine::GameObject gameObject) -> void { do some nasty stuff };
	auto func = [](int i) -> double { return 2*i/1.15; };
	double d = func(1);
	std::cout << d << std::endl;

	SDL_Window *window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* surface = nullptr;

	GameObjectManager* manager = new GameObjectManager();
	Game::CollisionManager *cm;
	std::map<std::string, engine::AnimationComponent> animations;
	
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
	
	SDL_Rect pos_spider;
	pos_spider.x = 32;
	pos_spider.y = 320;
	pos_spider.w = 0;
	pos_spider.h = 0;

	SDL_Rect scale_spider;
	scale_spider.x = 0;
	scale_spider.y = 0;
	scale_spider.w = 64;
	scale_spider.h = 64;

	SDL_Rect pos_monster;
	pos_monster.x = 320;
	pos_monster.y = 320;
	pos_monster.w = 0;
	pos_monster.h = 0;

	SDL_Rect scale_monster;
	scale_monster.x = 0;
	scale_monster.y = 0;
	scale_monster.w = 64;
	scale_monster.h = 64;

	engine::GameObject player = engine::GameObject::Create(engine::TransformComponent::Factory(pos, pos, &scale, engine::UnitSpeed::Fast));
	player.RegisterComponent(new engine::InputComponent);
	player.RegisterComponent(engine::StateComponent::Factory());
	player.tag = "player";
	engine::CollisionComponent::Factory(player);
	
	engine::GameObject spider = engine::GameObject::Create(engine::TransformComponent::Factory(pos_spider, pos_spider, &scale_spider, engine::UnitSpeed::Slow));
	spider.RegisterComponent(new engine::AiBasicComponent(&player));
	spider.RegisterComponent(engine::StateComponent::Factory());
	spider.tag = "enemy";
	engine::CollisionComponent::Factory(spider);

	engine::GameObject monster = engine::GameObject::Create(engine::TransformComponent::Factory(pos_monster, pos_monster, &scale_monster, engine::UnitSpeed::Slow));
	monster.RegisterComponent(new engine::AiBasicComponent(&player));
	monster.RegisterComponent(engine::StateComponent::Factory());
	monster.tag = "enemy";
	engine::CollisionComponent::Factory(monster);
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow("Chase the Shadow!", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
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
		surface = IMG_Load("resources/cts.ico");
		SDL_SetWindowIcon(window, surface); 
	}

	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	} else {
		player.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/princess.png", renderer));
		player.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/sparks.png", renderer));
		spider.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/villain.png", renderer));
		monster.RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/monster.png", renderer));

		Game::MapLoader loader =  Game::MapLoader();
		loader.LoadMap("resources/dorf_map.json", (*manager), renderer);

		manager->RegisterGameobject(&player);
		manager->RegisterGameobject(&spider);
		manager->RegisterGameobject(&monster);

		cm = new Game::CollisionManager();
		cm->RegisterGameobject(&player);
		cm->RegisterGameobject(&spider);
		cm->RegisterGameobject(&monster);

		GameLoop gameloop = GameLoop(renderer, manager, cm);
		gameloop.Run();
	}

	delete cm, manager;

	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}