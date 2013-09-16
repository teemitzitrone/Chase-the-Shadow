#pragma once
#include <SDL.h>
#include <vector>
#include "Component.h"
#include "TransformComponent.h"

class GameObject
{
public:
	virtual ~GameObject(void) {};
	void StartUp();
	void Input(SDL_Event*);
	void Update(double);
	void Render(SDL_Renderer*);
	void ShutDown();
	void RegisterComponent(Component*);
	std::vector<Component*> FilterComponent(std::string);

	static GameObject Create(Component* component = nullptr)
	{
		GameObject g = GameObject();
		if (component == nullptr)
		{
			component = TransformComponent::Factory();
		}
		g.RegisterComponent(component);

		return g;
	}

private:
	bool _alive;
	std::vector<Component*> _components;

	GameObject(void): _alive(true) { };
};
