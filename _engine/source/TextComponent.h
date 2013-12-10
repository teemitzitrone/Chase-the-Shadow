#ifndef _ENGINE_TEXT_COMPONENT_H
#define _ENGINE_TEXT_COMPONENT_H
#include "Component.h"
#include <SDL_image.h>
#include <map>

namespace engine
{
	class TextComponent :
		public Component
	{
	public:
		TextComponent(void): _texture(nullptr), Component("Text") {};
		TextComponent(SDL_Texture* texture): _texture(texture), Component("Text") {};
		virtual ~TextComponent(void) {};
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
