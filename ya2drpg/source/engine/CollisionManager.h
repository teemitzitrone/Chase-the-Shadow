#ifndef _GAME_COLLISION_MANAGER_H
#define _GAME_COLLISION_MANAGER_H
#include <_engine.h>

namespace Game
{
	class ScreenManager;

	class CollisionManager
	{
	private:
		std::map<const std::string, std::vector<engine::GameObject*>> _gameobjects;

	public:
		CollisionManager(void) {};
		virtual ~CollisionManager(void)
		{
			this->_gameobjects.clear();
		};
	
		void RegisterGameobject(engine::GameObject*);
		void UnregisterGameobject(engine::GameObject*);
		void Handle(ScreenManager*);
	};
}
#endif