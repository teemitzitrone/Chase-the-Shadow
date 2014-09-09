#ifndef _ENGINE_TEXT_COMPONENT_H
#define _ENGINE_TEXT_COMPONENT_H
#include "Component.h"
#include <SDL_image.h>
#include <map>

namespace engine
{
	class TextComponent :
		public ComponentInterface
	{
	public:
		TextComponent(void) : _texture(nullptr), ComponentInterface("Text") {};
		TextComponent(SDL_Texture* texture) : _texture(texture), ComponentInterface("Text") {};
		virtual ~TextComponent(void)
		{
			SDL_DestroyTexture(this->_texture);
		};
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		static TextComponent* Factory(
			const std::string,
			SDL_Renderer*,
			const std::string,
			SDL_Color,
			int fontSize = 16
		);

	private:
		SDL_Texture *_texture;
	};
}
#endif
