include_directories(${PROJECT_SOURCE_DIR}/vendors/catch)
add_executable(tests runner.cpp)
target_link_libraries(tests _engine)
