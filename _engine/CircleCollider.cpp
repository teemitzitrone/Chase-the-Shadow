#include "CircleCollider.h"

namespace engine {
    const bool
    CircleCollider::Collision(const Collider &collider) const {
        const CircleCollider *circle = dynamic_cast<const CircleCollider *>(&collider);

        if (circle != nullptr) {
            float distance = this->GetPosition().Distance(circle->GetPosition());

            return (distance <= (this->GetRadius() + circle->GetRadius()));
        }
        else {
            return false;
        }
    }

    void
    CircleCollider::SetRadius(double radius) {
        if (radius < 0.0) {
            radius = 0.0;
        }

        this->_radius = radius;
    }

    const double
    CircleCollider::GetRadius() const {
        return this->_radius;
    }

    std::ostream &
    operator<<(std::ostream &stream, const CircleCollider &cc) {
        return stream << "CircleCollider(" << cc.GetPosition() << ", radius " << cc.GetPosition() << ")";
    }
}
