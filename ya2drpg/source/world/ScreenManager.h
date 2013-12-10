#ifndef _GAME_SCREEN_MANAGER_H
#define _GAME_SCREEN_MANAGER_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <map>
#include <string>
#include "../engine/GameObjectManager.h"
#include "../engine/CollisionManager.h"

namespace Game
{
	struct Screen
	{
		GameObjectManager *objectManager;
		CollisionManager *cm;
	};

	class ScreenManager
	{
	public:
		static std::vector<std::string> maps;

		static ScreenManager* GetInstance();
		
		virtual ~ScreenManager(void)
		{
			delete this->_current->cm;
			delete this->_current->objectManager;
			delete this->_current;

			for (auto texture : engine::TextureComponent::Loaded())
			{
				SDL_DestroyTexture(texture.second);
			}

			Mix_FreeMusic(this->_music);
			Mix_CloseAudio();
			SDL_FreeSurface(this->_surface);
			SDL_DestroyRenderer(this->_renderer);
			SDL_DestroyWindow(this->_window);
			TTF_Quit();
			SDL_Quit();
		};

		bool Init();
		bool LoadMap(const std::string);
		void Run();

	protected:
		ScreenManager(void) {};

	private:
		static ScreenManager *instance;
		Screen *_current;
		std::map<std::string, Screen*> _loadedScreens;
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Surface *_surface;
		Mix_Music *_music;
	};
}
#endif
