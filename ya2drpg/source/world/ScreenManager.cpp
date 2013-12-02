#include "ScreenManager.h"
#include <iostream>
#include <_engine.h>
#include "..\engine\GameLoop.h"
#include "..\engine\MapLoader.h"

namespace Game
{
	ScreenManager* ScreenManager::instance = nullptr;

	ScreenManager*
	ScreenManager::GetInstance()
	{
		if (nullptr == ScreenManager::instance)
		{
			ScreenManager::instance = new ScreenManager();
		}
		
		return ScreenManager::instance;
	}

	bool
	ScreenManager::Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return false;
		}

		if (TTF_Init() == -1){
			std::cout << TTF_GetError() << std::endl;
			return false;
		}

		this->_window = SDL_CreateWindow("Chase the Shadow!", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
		if (this->_window == nullptr) {
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		} else {
			this->_renderer = SDL_CreateRenderer(
				this->_window, 
				-1, 
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
			);
			this->_surface = IMG_Load("resources/cts.ico");
			SDL_SetWindowIcon(this->_window, this->_surface); 
		}
	
		Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024);

		if (this->_renderer == nullptr) {
			std::cout << "SDL_Createthis->_renderer Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		} else {
			this->_music = Mix_LoadMUS("resources/sound/jus/41618__jus__cellos-down-down.wav");
			if (nullptr == this->_music)
			{
				std::cout << "Mix_LoadMUS Error: " << SDL_GetError() << std::endl;
			}
			// Mix_PlayMusic(this->_music, -1);

			return true;
		}
	}

	bool
	ScreenManager::LoadMap(const std::string name)
	{
		this->_current = new Screen();

		this->_current->objectManager = new GameObjectManager();
		this->_current->cm = new CollisionManager();
	
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

		engine::GameObject *player = new engine::GameObject(engine::GameObject::Create(engine::TransformComponent::Factory(pos, pos, &scale, engine::UnitSpeed::Fast)));
		player->RegisterComponent(new engine::InputComponent);
		player->RegisterComponent(engine::StateComponent::Factory());
		player->tag = "player";
		engine::CollisionComponent::Factory((*player));
	
		engine::GameObject *spider = new engine::GameObject(engine::GameObject::Create(engine::TransformComponent::Factory(pos_spider, pos_spider, &scale_spider, engine::UnitSpeed::Slow)));
		spider->RegisterComponent(new engine::AiBasicComponent(player));
		spider->RegisterComponent(engine::StateComponent::Factory());
		spider->tag = "enemy";
		engine::CollisionComponent::Factory((*spider));

		engine::GameObject *monster = new engine::GameObject(engine::GameObject::Create(engine::TransformComponent::Factory(pos_monster, pos_monster, &scale_monster, engine::UnitSpeed::Slow)));
		monster->RegisterComponent(new engine::AiBasicComponent(player));
		monster->RegisterComponent(engine::StateComponent::Factory());
		monster->tag = "enemy";
		engine::CollisionComponent::Factory((*monster));
		
		Game::MapLoader loader =  Game::MapLoader();
		loader.LoadMap(name, (*this->_current->objectManager), this->_renderer);

		player->RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/princess.png", this->_renderer));
		player->RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/sparks.png", this->_renderer));
		spider->RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/villain.png", this->_renderer));
		monster->RegisterComponent(engine::AnimationComponent::Factory("assets/sprites/characters/palumpa.png", this->_renderer, 5));
		
		this->_current->objectManager->RegisterGameobject(spider);
		this->_current->objectManager->RegisterGameobject(monster);
		this->_current->objectManager->RegisterGameobject(player);

		this->_current->cm->RegisterGameobject(player);
		this->_current->cm->RegisterGameobject(spider);
		this->_current->cm->RegisterGameobject(monster);

		/// @todo move me to Run();
		GameLoop loop = GameLoop(this->_renderer, this->_current->objectManager, this->_current->cm);

		loop.Run();
		return true;
	}

	void
	ScreenManager::Run()
	{
		
	}
}
