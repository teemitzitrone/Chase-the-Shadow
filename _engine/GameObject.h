#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SDL.h>
#include <vector>
#include "Vector2D.h"
#include "TransformComponent.h"

namespace engine {
    class GameObject {
    public:
        bool alive;
        std::string tag;

        virtual ~GameObject(void) {
            this->_components.clear();
        };

        void Input(SDL_Event *);

        void Update(double);

        void Render(SDL_Renderer *);

        void RegisterComponent(Component);

        Components FilterComponent(std::string);

        static GameObject Create(Component component = nullptr);

    private:
        Components _components;

        GameObject(void) : alive(true) {
        };
    };
}
#endif