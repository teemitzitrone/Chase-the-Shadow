#include <iostream>
#include "MapLoader.h"
#include "TextureComponent.h"

namespace Game
{
	void MapLoader::LoadMap(const std::string file, GameObjectManager& gameManager, SDL_Renderer* renderer)
	{
		try {
			Jzon::Object rootNode;
			Jzon::FileReader reader = Jzon::FileReader(file);

			if (reader.Read(rootNode)) {
				this->_loadGrid(rootNode);
				this->_convertLayers(rootNode, gameManager, renderer);
			}
		} catch (Jzon::NotFoundException v) {
			std::cout << "NotFoundException " << v.what() << std::endl;
		} catch (Jzon::TypeException v) {
			std::cout << "TypeException" << std::endl;
		}
	}

	void MapLoader::_loadGrid(Jzon::Object rootNode)
	{
		const Jzon::Array &stuff = rootNode.Get("tilesets").AsArray();
		for (Jzon::Array::const_iterator it = stuff.begin(); it != stuff.end(); ++it)
		{
			if ((*it).IsObject())
			{
				Jzon::Object data = (*it).AsObject();
				Grid _g = Grid();
				_g.h = data.Get("tileheight").ToInt();
				_g.w = data.Get("tilewidth").ToInt();
				_g.x = data.Get("imagewidth").ToInt();
				_g.y = data.Get("imageheight").ToInt();

				int index = data.Get("firstgid").ToInt();

				_g.texture = data.Get("image")
					.ToString()
					.replace(
					data.Get("image").ToString().find("../../"),
					std::string("../../").length(),
					""
					);

				for (int y = 0; y < (_g.y/_g.h); y++)
				{
					for (int x = 0; x < (_g.x/_g.w); x++)
					{
						Grid g = Grid(_g);
						g.x = x * _g.w;
						g.y = y * _g.h;
						this->_grid[index] = g;
						index++;
					}
				}
			}
		}
	}

	void MapLoader::_convertLayers(Jzon::Object rootNode, GameObjectManager& gameManager, SDL_Renderer* renderer)
	{
		const Jzon::Array &stuff = rootNode.Get("layers").AsArray();
		for (Jzon::Array::const_iterator it = stuff.begin(); it != stuff.end(); ++it)
		{
			Jzon::Object data = (*it).AsObject();
			if (data.Get("type").ToString() == "tilelayer") {
				Jzon::Array tiles = data.Get("data").AsArray();

				for (int y = 0; y < data.Get("height").ToInt(); y++)
				{
					for (int x = 0; x < data.Get("width").ToInt(); x++)
					{
						try {
							int tile = tiles.Get((y*data.Get("width").ToInt())+x).ToInt();
							if (tile > 0)
							{
								Grid g = this->_grid[tile];
								SDL_Rect pos;
								pos.x = x * rootNode.Get("tilewidth").ToInt() + data.Get("x").ToInt();
								pos.y = y * rootNode.Get("tileheight").ToInt() + data.Get("y").ToInt();
								pos.w = 0;
								pos.h = 0;

								SDL_Rect* scale = new SDL_Rect();
								scale->x = g.x;
								scale->y = g.y;
								scale->w = g.w;
								scale->h = g.h;

								engine::GameObject* _t = new engine::GameObject(engine::GameObject::Create(engine::TransformComponent::Factory(pos, pos, scale, engine::UnitSpeed::None)));
								_t->RegisterComponent(engine::TextureComponent::Factory(g.texture, renderer));

								gameManager.RegisterGameobject(_t);
							}
						} catch (Jzon::NotFoundException v) {
							std::cout << data.Get("name").ToString() << " " <<  (y*data.Get("width").ToInt())+x << std::endl;
						}
					}
				}
			}
		}
	}
}