#include "StateComponent.h"


namespace engine
{
	StateComponent::~StateComponent(void)
	{
	}

	StateComponent* StateComponent::Factory()
	{
		return new StateComponent();
	}

	void StateComponent::Input(GameObject& gameobject, SDL_Event* event) 
	{
		TransformComponent* t = (TransformComponent*)gameobject.FilterComponent("Transform").front();
		SDL_Rect* scale = t->GetScale();

		switch (event->key.keysym.sym) {
			case SDLK_w:
				scale->y = (int)State::PLAYABLE_UP * scale->h; 
				break;
			case SDLK_d:
				scale->y = (int)State::PLAYABLE_RIGHT * scale->h; 
				break;
			case SDLK_s:
				scale->y = (int)State::PLAYABLE_DOWN * scale->h; 
				break;
			case SDLK_a:
				scale->y = (int)State::PLAYABLE_LEFT * scale->h; 
				break;
			default:
				break;
		}
	}

	void StateComponent::Update(GameObject&, double)
	{
	}

	void StateComponent::Render(GameObject&, SDL_Renderer*)
	{
	}
}