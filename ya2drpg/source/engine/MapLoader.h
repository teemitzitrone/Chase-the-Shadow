#include "GameObjectManager.h"
#include "..\vendor\Jzon.h"

void testJzon();

namespace Game
{
	class MapLoader
	{
	public:
		MapLoader(void) {};
		virtual ~MapLoader(void) {};
		void LoadMap(const std::string, GameObjectManager&);
	};
}
