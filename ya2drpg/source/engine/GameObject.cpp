#include "GameObject.h"

void GameObject::StartUp()
{
}

void GameObject::Input(SDL_Event* input)
{
	std::vector<Component*>::iterator it;
	it = this->_components.begin();

	while (it != this->_components.end())
	{
		(**it).Input(input);
		it++;
	}
}

void GameObject::Update()
{
	std::vector<Component*>::iterator it;
	it = this->_components.begin();

	while (it != this->_components.end())
	{
		(**it).Update(*this);
		it++;
	}
}

void GameObject::Render(SDL_Renderer *renderer)
{
	std::vector<Component*>::iterator it;
	it = this->_components.begin();

	while (it != this->_components.end())
	{
		(**it).Render(*this, renderer);
		it++;
	}
}

void GameObject::ShutDown()
{
}

void GameObject::RegisterComponent(Component* component)
{
	this->_components.push_back(component);
}

std::vector<Component*> GameObject::FilterComponent(std::string tag_)
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
