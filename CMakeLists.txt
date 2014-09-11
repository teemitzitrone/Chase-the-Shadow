cmake_minimum_required (VERSION 2.8.4)
ADD_DEFINITIONS(
    -std=gnu++0x # Or -std=c++0x
)
project (ya2drpg)

set(ENABLE_SOLUTION_FOLDERS "TRUE")
if(ENABLE_SOLUTION_FOLDERS)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "!CMakeTargets")
endif()

include_directories(".")

add_subdirectory (_engine)
add_subdirectory (tests)
add_subdirectory (ya2drpg)