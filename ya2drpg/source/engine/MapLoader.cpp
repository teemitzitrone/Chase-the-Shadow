#include <iostream>
#include "MapLoader.h"

void testJzon() {
	Jzon::Object rootNode;
	const std::string file = "resources/dorf_map.json";

	try {
		Jzon::FileReader reader = Jzon::FileReader(file);

		if (reader.Read(rootNode)) {
			for (Jzon::Object::iterator it = rootNode.begin(); it != rootNode.end(); ++it)
			{
					std::string name = (*it).first;
					Jzon::Node &node = (*it).second;

					std::cout << name << " = ";
					if (node.IsValue())
					{
							switch (node.AsValue().GetValueType())
							{
							case Jzon::Value::VT_NULL   : std::cout << "null"; break;
							case Jzon::Value::VT_STRING : std::cout << node.ToString(); break;
							case Jzon::Value::VT_NUMBER : std::cout << node.ToFloat(); break;
							case Jzon::Value::VT_BOOL   : std::cout << (node.ToBool()?"true":"false"); break;
							}
					}
					else if (node.IsArray())
					{
							std::cout << "*Array*";
					}
					else if (node.IsObject())
					{
							std::cout << "*Object*";
					}
					std::cout << std::endl;
			}

			const Jzon::Array &stuff = rootNode.Get("listOfStuff").AsArray();
			for (Jzon::Array::const_iterator it = stuff.begin(); it != stuff.end(); ++it)
			{
					std::cout << (*it).ToString() << std::endl;
			}

		}
	} catch (Jzon::NotFoundException v) {
	}
}