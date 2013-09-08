#include "TextureComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include <vector>
#include <iostream>

void TextureComponent::Render(GameObject& gameObject, SDL_Renderer* renderer)
{
	std::vector<Component*> hits = gameObject.FilterComponent("Transform");
	TransformComponent* transform;
	transform = dynamic_cast<TransformComponent*> (hits.front());

	SDL_Rect position = transform->GetPosition();
	SDL_Rect scale = transform->GetScale();

	position.h = scale.h;
	position.w = scale.w;
	
	SDL_RenderCopy(renderer, this->_texture, &scale, &position);
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