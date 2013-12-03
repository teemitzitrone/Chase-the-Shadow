#include "CollisionManager.h"
#include "../world/ScreenManager.h"
#include <iostream>

namespace Game
{
	void
	CollisionManager::RegisterGameobject(engine::GameObject* gameObject)
	{
		if (gameObject->FilterComponent("collider").size() > 0)
		{
			this->_gameobjects[gameObject->tag].push_back(gameObject);
		}
	}
	
	void
	CollisionManager::UnregisterGameobject(engine::GameObject* gameObject)
	{
		std::string listName = gameObject->tag;

		auto gameobjectIterator = this->_gameobjects[listName].begin();
	
		while (gameobjectIterator != this->_gameobjects[listName].end()) {
			if ((*gameobjectIterator) != gameObject) {
				gameobjectIterator++;
				continue;
			} else {
				this->_gameobjects[listName].erase(gameobjectIterator);
				break;
			}
		};
	}

	void
	CollisionManager::Handle(ScreenManager* screen)
	{
		for (auto player = this->_gameobjects["player"].begin(); player != this->_gameobjects["player"].end(); player++)
		{
			engine::CollisionComponent *collider = static_cast<engine::CollisionComponent*> ((**player).FilterComponent("collider").front());
			const engine::Collider *playerCollider = collider->GetCollider();

			if (!this->_gameobjects["enemy"].empty())
			{
				/* Check against enemies
				 */
				for (auto enemy = this->_gameobjects["enemy"].begin(); enemy != this->_gameobjects["enemy"].end(); enemy++)
				{
					engine::CollisionComponent *enemyCollider = static_cast<engine::CollisionComponent*> ((**enemy).FilterComponent("collider").front());
					const engine::Collider *circle = enemyCollider->GetCollider();

					if (playerCollider->Collision(*circle))
					{
						(**enemy).alive = false;
					}

				}
			}
			else
			{
				// @todo remove tem hack
				if (!ScreenManager::maps.empty())
				{
					std::string map = ScreenManager::maps.back();
					ScreenManager::maps.pop_back();

					screen->LoadMap(map);
				}
				else
				{
					exit(1);
				}
			}
			

			/* Check against events
			 */
			for (auto event = this->_gameobjects["event"].begin(); event != this->_gameobjects["event"].end(); event++)
			{
				engine::CollisionComponent *eventCollider = static_cast<engine::CollisionComponent*> ((**event).FilterComponent("collider").front());
				const engine::Collider *circle = eventCollider->GetCollider();

				if (playerCollider->Collision(*circle))
				{
					// @todo add event Component
				}
			}
		}
	}
}
