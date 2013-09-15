#include "AnimationComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include <vector>
#include <iostream>

void AnimationComponent::Update(GameObject& gameObject)
{
	std::vector<Component*> hits = gameObject.FilterComponent("Transform");
	TransformComponent* transform = dynamic_cast<TransformComponent*> (hits.front());

	SDL_Rect* scale = transform->GetScale();

	// x -> 0 to (scale.w * frames)
	int max = scale->w * (this->_frames - 1);
	if (scale->x == max)
	{
		scale->x = 0;
	} else {
		scale->x += scale->w;
	}
}

AnimationComponent* AnimationComponent::Factory(const std::string image, SDL_Renderer* renderer, int frames)
{
	SDL_Texture *texture = IMG_LoadTexture(renderer, image.c_str());
	if (texture == nullptr) {	
		std::cout << "ERROR " << image.c_str() << " " << IMG_GetError() << std::endl;
	} else {
		std::cout << "SUCCESS " << image.c_str() << std::endl;
	}
	return new AnimationComponent(texture, frames);
}