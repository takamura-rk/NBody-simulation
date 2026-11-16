cmake_minimum_required(VERSION 3.15)
project(nbody VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(COMMON_COMPILE_FLAGS
    $<$<CONFIG:Debug>:-Wall -Wextra -g>
    $<$<CONFIG:Release>:-Wall -Wextra -03 -DNDEBUG>
)

add_executable(grav src/main.c src/Nbody.c)
target_include_directories(grav PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_options(grav PRIVATE ${COMMON_COMPILE_FLAGS})

# Unit tests
# Fetch and build the Unity testing framework
include(FetchContent)
FetchContent_Declare(
    unity
    GIT_REPOSITORY  https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG         v2.6.1
    GIT_SHALLOW TRUE # Only download the specific tag, not full history
)

# Make Unity available but don't add to ALL target by default
# This is important to avoid installing unity dependencies which are only needed for testing
# but are not required in the release version of the project
FetchContent_GetProperties(unity)
if(NOT unity_POPULATED)
    FetchContent_Populate(unity)
    add_subdirectory(${unity_SOURCE_DIR} ${unity_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# Build the test runner executable
add_executable(test_runner tests/test_runner.c )

target_include_directories(test_runner PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(test_runner PRIVATE unity m)

add_custom_target(test test_runner
    DEPENDS $<TARGET_FILE:test_runner>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running unit tests :"
)

