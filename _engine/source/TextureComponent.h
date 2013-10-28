#ifndef _TEXTURECOMPONENT_H
#define _TEXTURECOMPONENT_H
#pragma once
#include "Component.h"
#include <SDL_image.h>

namespace engine
{
	class TextureComponent :
		public Component
	{
	public:
		TextureComponent(void): _texture(nullptr), Component("Texture") {};
		TextureComponent(SDL_Texture* texture): _texture(texture), Component("Texture") {};
		virtual ~TextureComponent(void) {};
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		static TextureComponent* Factory(const std::string, SDL_Renderer*);
	protected:
		SDL_Rect* _scale;
	private:
		SDL_Texture* _texture;
	};
}
#endif