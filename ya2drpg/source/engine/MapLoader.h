#include "GameObjectManager.h"
#include "..\vendor\Jzon.h"
#include <map>

namespace Game
{
	struct Grid
	{
		std::string texture;
		int x, y, w, h;
	};

	class MapLoader
	{
	public:
		MapLoader(void) {};
		virtual ~MapLoader(void) {};
		void LoadMap(const std::string, GameObjectManager&);
	private:
		std::map<int, Game::Grid> _grid;
	};
}
