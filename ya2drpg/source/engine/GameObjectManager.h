#pragma once
#include <vector>
#include "GameObject.h"

class GameObjectManager
{
	std::vector<GameObject*> _gameobjects;

public:
	GameObjectManager(void);
	virtual ~GameObjectManager(void);
	
	void RegisterGameobject(GameObject*);
	void UnregisterGameobject(GameObject*);


#if 0
    typedef std::vector<GameObject*>::iterator iterator;
    typedef std::vector<GameObject*>::const_iterator const_iterator;

	iterator begin() { return this->_gameobjects.begin(); }
    const_iterator begin() const { return this->_gameobjects.begin(); }

    iterator end() { return this->_gameobjects.end(); }
    const_iterator end() const { return this->_gameobjects.end(); }

#endif
	std::vector<GameObject*> GameObjects() { return this->_gameobjects; }
};

