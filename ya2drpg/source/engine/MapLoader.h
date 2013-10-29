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
		void LoadMap(const std::string, GameObjectManager&, SDL_Renderer*);
	private:
		std::map<int, Game::Grid> _grid;

		void _loadGrid(Jzon::Object);
		void _convertLayers(Jzon::Object, GameObjectManager&, SDL_Renderer*);
	};
}
