#include "GameObjectManager.h"

#include <iostream>
GameObjectManager::GameObjectManager(void)
{
}

GameObjectManager::~GameObjectManager(void)
{
	for (auto gameobject : this->_gameobjects)
	{
		delete gameobject;
	}

	this->_gameobjects.clear();
}

void GameObjectManager::RegisterGameobject(engine::GameObject* gameObject)
{
	this->_gameobjects.push_back(gameObject);
}

void GameObjectManager::UnregisterGameobject(engine::GameObject* gameObject)
{
	auto gameobjectIterator = this->_gameobjects.begin();
	
	while (gameobjectIterator != this->_gameobjects.end()) {
		if ((*gameobjectIterator) != gameObject) {
			gameobjectIterator++;
			continue;
		} else {
			this->_gameobjects.erase(gameobjectIterator);
			break;
		}
	};

}