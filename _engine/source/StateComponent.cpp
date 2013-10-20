#include "StateComponent.h"


namespace engine
{
	StateComponent::~StateComponent(void)
	{
	}

	StateComponent* StateComponent::Factory(AnimationComponent* animation, State state)
	{
		return new StateComponent(animation, state);
	}

	void StateComponent::Input(SDL_Event* event) 
	{
	}

	void StateComponent::Update(GameObject&, double)
	{
	}

	void StateComponent::Render(GameObject&, SDL_Renderer*)
	{
	}
}