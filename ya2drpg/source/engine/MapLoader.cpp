#include <iostream>
#include "MapLoader.h"

namespace Game
{
	void MapLoader::LoadMap(const std::string file, GameObjectManager& gameManager)
	{
		try {
			Jzon::Object rootNode;
			Jzon::FileReader reader = Jzon::FileReader(file);

			if (reader.Read(rootNode)) {
				const Jzon::Array &stuff = rootNode.Get("tilesets").AsArray();
				int id = 1;
				for (Jzon::Array::const_iterator it = stuff.begin(); it != stuff.end(); ++it)
				{
					Grid _g;
					if ((*it).IsObject())
					{
						_g = Grid();
						_g.texture = "mau";
						_g.h, _g.w, _g.x, _g.y = 1;
					}
					this->_grid[id] = _g;
					++id;
				}
				std::cout << this->_grid[2].texture.c_str() << std::endl;
			}
		} catch (Jzon::NotFoundException v) {
			std::cout << "NotFoundException" << std::endl;
		} catch (Jzon::ValueException v) {
			std::cout << "ValueException" << std::endl;
		} catch (Jzon::TypeException v) {
			std::cout << "TypeException" << std::endl;
		}
	}
}