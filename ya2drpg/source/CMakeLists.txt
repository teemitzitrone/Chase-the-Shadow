include_directories(world)

include_directories(${PROJECT_SOURCE_DIR}/vendors/SDL2/include)
include_directories(${PROJECT_SOURCE_DIR}/vendors/SDL2_image/include)
include_directories(${PROJECT_SOURCE_DIR}/vendors/SDL2_mixer/include)
include_directories(${PROJECT_SOURCE_DIR}/vendors/SDL2_ttf/include)

add_subdirectory(world)
add_executable(ya2drpg main.cpp)
target_link_libraries(ya2drpg _engine)