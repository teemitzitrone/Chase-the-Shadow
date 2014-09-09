#include "TextComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include <vector>
#include <SDL_ttf.h>

namespace engine
{
	void TextComponent::Render(GameObject& gameObject, SDL_Renderer* renderer)
	{
		Components hits = gameObject.FilterComponent("Transform");
		TransformComponent* transform = dynamic_cast<TransformComponent*> (hits.front().get());

		SDL_Rect pos = transform->GetPosition();
	
		SDL_QueryTexture(this->_texture, NULL, NULL, &pos.w, &pos.h);
		SDL_RenderCopy(renderer, this->_texture, NULL, &pos);
	}

	void TextComponent::Input(GameObject&, SDL_Event*)
	{
		/** **/
	}

	void TextComponent::Update(GameObject&, double)
	{
		/** **/
	}

	TextComponent* TextComponent::Factory(
		const std::string fontFile,
		SDL_Renderer* renderer,
		const std::string message,
		SDL_Color color,
		int fontSize
	) {
		TTF_Font *font = nullptr;
		font = TTF_OpenFont(fontFile.c_str(), fontSize);

		SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
		SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);

		SDL_FreeSurface(surf);
		TTF_CloseFont(font);
 
		return new TextComponent(texture);
	}
}
