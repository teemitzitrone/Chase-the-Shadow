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
	SDL_Rect *scale = transform->GetScale();

	position.h = scale->h;
	position.w = scale->w;
	
	SDL_RenderCopy(renderer, this->_texture, scale, &position);
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
	SDL_Texture *texture = IMG_LoadTexture(renderer, image.c_str());
	if (texture == nullptr) {	
		std::cout << "ERROR " << image.c_str() << " " << IMG_GetError() << std::endl;
	} else {
		std::cout << "SUCCESS " << image.c_str() << std::endl;
	}
	return new TextureComponent(texture);
}