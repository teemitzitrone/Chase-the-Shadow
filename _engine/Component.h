#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <SDL.h>
#include <string>
#include <memory>
#include <vector>

namespace engine {
    class GameObject;

    class ComponentInterface {
    public:
        ComponentInterface(std::string tag) : tag(tag) {
        };

        virtual ~ComponentInterface(void) {
        };

        virtual void Input(GameObject &, SDL_Event *) = 0;

        virtual void Update(GameObject &, double) = 0;

        virtual void Render(GameObject &, SDL_Renderer *) = 0;

        std::string tag;
    };

    typedef std::shared_ptr<ComponentInterface> Component;
    typedef std::vector<Component> Components;
}
#endif