#include "AnimationComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include <vector>

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

AnimationComponent* AnimationComponent::Factory(const std::string image, SDL_Renderer* renderer, int frames = 8)
{
	SDL_Surface *surface = SDL_LoadBMP(image.c_str());
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return new AnimationComponent(texture, frames);
}