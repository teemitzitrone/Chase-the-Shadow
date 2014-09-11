#include <catch.hpp>
#include <_engine/CircleCollider.h>

TEST_CASE( "Circle Collision", "[collision]" ) {
    engine::CircleCollider circleA = engine::CircleCollider(engine::Vector2D(0, 0), 1.0);
    engine::CircleCollider circleB = engine::CircleCollider(engine::Vector2D(0, 0), 1.0);

    SECTION( "Circle radius can not be lower then zero" ) {
        circleB.SetRadius(-0.1);

        REQUIRE( circleB.GetRadius() == 0.0 );
    }

    SECTION( "Circles with same position" ) {
        REQUIRE( circleA.GetPosition() == circleB.GetPosition() );
        REQUIRE( circleA.Collision(circleB) != 0 );
    }

    SECTION( "Circles with intersect" ) {
        circleB.SetPosition(engine::Vector2D(1, 1));
        circleB.SetRadius(1.5);

        REQUIRE( circleA.GetPosition() != circleB.GetPosition() );
        REQUIRE( circleA.Collision(circleB) != 0 );
    }

    SECTION( "Circles with collision" ) {
        circleB.SetPosition(engine::Vector2D(1, 1));

        REQUIRE( circleA.GetPosition() != circleB.GetPosition() );
        REQUIRE( circleA.Collision(circleB) != 0 );
    }

    SECTION( "Circles with different position and distance > r+r" ) {
        circleB.SetPosition(engine::Vector2D(4, 4));

        REQUIRE( circleA.GetPosition() != circleB.GetPosition() );
        REQUIRE( circleA.Collision(circleB) == 0 );
    }
}
