#pragma once
#include <SDL.h>
#include <vector>
#include "Component.h"

class GameObject
{
public:
	GameObject(void): _alive(true) { };
	virtual ~GameObject(void) {};
	virtual void StartUp() = 0;
	virtual void Input(SDL_Event*) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer*) = 0;
	virtual void ShutDown() = 0;
	void RegisterComponent(Component* component)
	{
		this->_components.push_back(component);
	}

	std::vector<Component*> FilterComponent(std::string tag_)
	{
		std::vector<Component*> hits;

		std::vector<Component*>::iterator it;
		it = this->_components.begin();
		while (it != this->_components.end())
		{
			if ((**it).tag == tag_) {
				hits.push_back(*it);
			}
			it++;
		}

		return hits;
	}

protected:
	bool _alive;
	std::vector<Component*> _components;
};
