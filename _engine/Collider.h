#ifndef _COLLIDER_H
#define _COLLIDER_H

#include "Vector2D.h"

namespace engine {
    class Collider {
    public:
        Collider(void) {
        };

        Collider(const Vector2D position) : _position(position) {
        };

        virtual ~Collider(void) {
        };

        virtual bool Collision(const Collider &) const = 0;

        void SetPosition(const Vector2D position) {
            this->_position = position;
        }

        const Vector2D GetPosition() const {
            return this->_position;
        }

    private:
        Vector2D _position;

        friend std::ostream &operator<<(std::ostream &stream, const Collider &c) {
            return stream << "Collider(" << c.GetPosition() << ")";
        }
    };
}
#endif
