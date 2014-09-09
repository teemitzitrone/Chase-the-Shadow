#include "AnimationComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include <vector>
#include <iostream>

namespace engine
{
	void AnimationComponent::Update(GameObject& gameObject, double delay)
	{
		if (nullptr == this->_scale) {
			Components hits = gameObject.FilterComponent("Transform");
			TransformComponent *transform = dynamic_cast<TransformComponent*> (hits.front().get());
			this->_scale = new SDL_Rect(*transform->GetScale());
		}

		// x -> 0 to (scale.w * frames)
		int max = this->_scale->w * (this->_frames - 1);
		this->_timeToAnimation -= delay;
	
		if ((int)this->_timeToAnimation <= 0) {
			if (this->_scale->x == max)
			{
				this->_scale->x = 0;
			} else {
				this->_scale->x += this->_scale->w;
			}

			this->_timeToAnimation = this->_animation / this->_speed;
		}
	}

	AnimationComponent* AnimationComponent::Factory(const std::string image, SDL_Renderer* renderer, int frames)
	{
		SDL_Texture *texture;
		
		if (TextureComponent::Loaded()[image] == nullptr)
		{
			texture = IMG_LoadTexture(renderer, image.c_str());
			if (texture == nullptr) {
				std::cout << "ERROR " << image.c_str() << " " << IMG_GetError() << std::endl;
			}
			else {
				std::cout << "SUCCESS " << image.c_str() << std::endl;
			}
		}
		else
		{
			texture = TextureComponent::Loaded()[image];
		}

		AnimationComponent *_t = new AnimationComponent(texture, frames);
		_t->textureName = image;

		return _t;
	}
}
