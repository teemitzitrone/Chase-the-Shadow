#include "TextureComponent.h"

void TextureComponent::Render(GameObject& gameObject, SDL_Renderer* renderer)
{
	SDL_Rect pos;
	pos.x = 0;
	pos.y = 0;

	SDL_QueryTexture(this->_texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(renderer, this->_texture, NULL, &pos);
}

void TextureComponent::Input(SDL_Event*)
{
	/** **/
}

void TextureComponent::Update(GameObject&)
{
	/** **/
}

TextureComponent* TextureComponent::Factory(const std::string image, SDL_Renderer* renderer)
{
	SDL_Surface *surface = SDL_LoadBMP(image.c_str());
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return new TextureComponent(texture);
}