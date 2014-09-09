#ifndef _CIRCLECOLLIDER_H
#define _CIRCLECOLLIDER_H

#include "Collider.h"

namespace engine {
    class CircleCollider : public Collider {
    public:
        CircleCollider(void) {
        };

        CircleCollider(const Vector2D position, double radius) : Collider(position), _radius(radius) {
        };

        virtual ~CircleCollider(void) {
        };

        const virtual bool Collision(const Collider &) const;

        void SetRadius(double);

        const double GetRadius() const;

    private:
        double _radius;

        friend std::ostream &operator<<(std::ostream &, const CircleCollider &);
    };
}
#endif
