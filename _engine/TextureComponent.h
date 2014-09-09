#ifndef _TEXTURECOMPONENT_H
#define _TEXTURECOMPONENT_H
#include "Component.h"
#include <SDL_image.h>
#include <map>

namespace engine
{
	class TextureComponent :
		public ComponentInterface
	{
	public:
		std::string textureName;

		TextureComponent(void) : _texture(nullptr), ComponentInterface("Texture") {};
		TextureComponent(SDL_Texture* texture) : _texture(texture), ComponentInterface("Texture") {};
		virtual ~TextureComponent(void)
		{
			SDL_DestroyTexture(this->_texture);
			TextureComponent::_loaded.erase(this->textureName);
		};
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		static TextureComponent* Factory(const std::string, SDL_Renderer*);
		static std::map<std::string, SDL_Texture*> Loaded() { return TextureComponent::_loaded; }

	protected:
		SDL_Rect* _scale;
	private:
		SDL_Texture *_texture;
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