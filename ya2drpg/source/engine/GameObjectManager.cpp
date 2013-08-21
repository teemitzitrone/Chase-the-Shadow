#include "GameObjectManager.h"

#include <iostream>
GameObjectManager::GameObjectManager(void)
{
}

GameObjectManager::~GameObjectManager(void)
{
}

void GameObjectManager::RegisterGameobject(GameObject* gameObject)
{
	this->_gameobjects.push_back(gameObject);
}

void GameObjectManager::UnregisterGameobject(GameObject* gameObject)
{
	auto gameobjectIterator = this->_gameobjects.begin();
	
	while (gameobjectIterator != this->_gameobjects.end()) {
		if ((*gameobjectIterator) != gameObject) {
			gameobjectIterator++;
			std::cout << "nope" << std::endl;
			continue;
		} else {
			std::cout << "yep" << std::endl;
			this->_gameobjects.erase(gameobjectIterator);
		}
	};

}