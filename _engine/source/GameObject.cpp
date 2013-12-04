#include "GameObject.h"

namespace engine
{
	GameObject GameObject::Create(Component component)
	{
		GameObject g = GameObject();
		if (component == nullptr)
		{
			component = Component(TransformComponent::Factory());
		}
		
		g.RegisterComponent(component);
		
		return g;
	}

	void GameObject::Input(SDL_Event* input)
	{
		Components::iterator it;
		it = this->_components.begin();

		while (it != this->_components.end())
		{
			(**it).Input(*this, input);
			it++;
		}
	}

	void GameObject::Update(double delay)
	{
		Components::iterator it;
		it = this->_components.begin();

		while (it != this->_components.end())
		{
			(**it).Update(*this, delay);
			it++;
		}
	}

	void GameObject::Render(SDL_Renderer *renderer)
	{
		Components::iterator it;
		it = this->_components.begin();

		while (it != this->_components.end())
		{
			(**it).Render(*this, renderer);
			it++;
		}
	}

	void GameObject::RegisterComponent(Component component)
	{
		this->_components.push_back(component);
	}

	///
	/// <summary>
	/// Filter a GameObject's components for a specific one
	/// </summary>
	///
	/// <param name="tag_" type="std::string">The tag to be filtered for</param>
	///
	Components GameObject::FilterComponent(std::string tag_)
	{
		Components hits;

		Components::iterator it;
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
}