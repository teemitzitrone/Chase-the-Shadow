#include "Player.h"

void Player::StartUp()
{
}

void Player::Input(SDL_Event *input)
{
	std::vector<Component*>::iterator it;
	it = this->_components.begin();

	while (it != this->_components.end())
	{
		(**it).Input(input);
		it++;
	}
}

void Player::Update()
{
	std::vector<Component*>::iterator it;
	it = this->_components.begin();

	while (it != this->_components.end())
	{
		(**it).Update(*this);
		it++;
	}
}

void Player::Render(SDL_Renderer *renderer)
{
	std::vector<Component*>::iterator it;
	it = this->_components.begin();

	while (it != this->_components.end())
	{
		(**it).Render(*this, renderer);
		it++;
	}
}
void Player::ShutDown()
{
}

void Player::RegisterComponent(Component *component)
{
	this->_components.push_back(component);
}