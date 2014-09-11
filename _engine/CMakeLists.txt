include_directories(${PROJECT_SOURCE_DIR}/vendors/SDL2/include)
#include_directories(${PROJECT_SOURCE_DIR}/vendors/SDL2_image/include)
#include_directories(${PROJECT_SOURCE_DIR}/vendors/SDL2_mixer/include)
#include_directories(${PROJECT_SOURCE_DIR}/vendors/SDL2_ttf/include)

add_library(_engine SHARED _engine.h Vector2D.cpp Collider.h CircleCollider.cpp)
SET_TARGET_PROPERTIES(_engine PROPERTIES LINKER_LANGUAGE CXX)