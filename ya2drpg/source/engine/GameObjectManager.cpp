#include "GameObjectManager.h"

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
	int position = 0;
	auto gameobjectIterator = this->_gameobjects.begin();
	
	while (gameobjectIterator != this->_gameobjects.end()) {
		if ((*gameobjectIterator) != gameObject) {
			position++;
			continue;
		} else {
			this->_gameobjects.erase(this->_gameobjects.begin() + position);
		}
	};

}