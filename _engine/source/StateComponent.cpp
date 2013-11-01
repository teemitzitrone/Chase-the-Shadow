#include "StateComponent.h"
#include "InputComponent.h"

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
		InputComponent* input = dynamic_cast<InputComponent*> (gameobject.FilterComponent("Input").front());

		Direction direction = input->GetDirection();
		SDL_Rect* scale = t->GetScale();

		switch (direction) {
		case Direction::up:
				scale->y = (int)State::PLAYABLE_UP * scale->h; 
				break;
			case Direction::right:
				scale->y = (int)State::PLAYABLE_RIGHT * scale->h; 
				break;
			case Direction::down:
				scale->y = (int)State::PLAYABLE_DOWN * scale->h; 
				break;
			case Direction::left:
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