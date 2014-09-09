add_library(_engine _engine.h Vector2D.cpp Collider.h CircleCollider.cpp)
SET_TARGET_PROPERTIES(_engine PROPERTIES LINKER_LANGUAGE CXX)