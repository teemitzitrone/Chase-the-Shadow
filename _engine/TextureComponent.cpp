#include "TextureComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include <vector>
#include <iostream>

namespace engine
{
	TextureComponent::Textures TextureComponent::_loaded = TextureComponent::_initTextures(); 

	void TextureComponent::Render(GameObject& gameObject, SDL_Renderer* renderer)
	{
		Components hits = gameObject.FilterComponent("Transform");
		TransformComponent* transform = dynamic_cast<TransformComponent*> (hits.front().get());

		SDL_Rect position = transform->GetPosition();
		SDL_Rect* scale = transform->GetScale();

		if (nullptr != this->_scale) {
			scale->x = this->_scale->x;
		}

		position.h = scale->h;
		position.w = scale->w;
		
		SDL_RenderCopy(renderer, this->_texture, scale, &position);
	}

	void TextureComponent::Input(GameObject&, SDL_Event*)
	{
		/** **/
	}

	void TextureComponent::Update(GameObject&, double)
	{
		/** **/
	}

	TextureComponent* TextureComponent::Factory(const std::string image, SDL_Renderer* renderer)
	{
		SDL_Texture* texture;
		if (TextureComponent::_loaded[image] == nullptr)
		{
			texture = IMG_LoadTexture(renderer, image.c_str());
			if (texture == nullptr) {	
				std::cout << "ERROR " << image.c_str() << " " << IMG_GetError() << std::endl;
			} else {
				std::cout << "SUCCESS " << image.c_str() << std::endl;
			}
			TextureComponent::_loaded[image] = texture;
		} else {
			texture = TextureComponent::_loaded[image];
		}

		TextureComponent *_t = new TextureComponent(texture);
		_t->textureName = image;

		return _t;
	}
}
