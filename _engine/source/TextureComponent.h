#ifndef _TEXTURECOMPONENT_H
#define _TEXTURECOMPONENT_H
#include "Component.h"
#include <SDL_image.h>
#include <map>

namespace engine
{
	class TextureComponent :
		public Component
	{
	public:
		TextureComponent(void): _texture(nullptr), Component("Texture") {};
		TextureComponent(SDL_Texture* texture): _texture(texture), Component("Texture") {};
		virtual ~TextureComponent(void)
		{
			delete this->_texture;
		};
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		static TextureComponent* Factory(const std::string, SDL_Renderer*);

	protected:
		SDL_Rect* _scale;
	private:
		SDL_Texture* _texture;
		typedef std::map<std::string, SDL_Texture*> Textures;
		static Textures _loaded;
		static Textures _initTextures()
		{
			Textures map;
			map["nan"] = nullptr;

			return map;
		}
	};
}
#endif