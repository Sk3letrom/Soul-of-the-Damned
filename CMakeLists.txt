cmake_minimum_required(VERSION 3.15)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(Soul_of_the_Damned LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)

FetchContent_MakeAvailable(raylib)

file(GLOB SOURCES "src/*.cpp" "src/entity/*.cpp" "src/core/*.cpp" "src/combat/*.cpp" "src/ui/*.cpp")

# No Windows, em Release, criar executável GUI (sem console)
if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(Soul_of_the_Damned WIN32 ${SOURCES})
else()
    add_executable(Soul_of_the_Damned ${SOURCES})
endif()

target_include_directories(Soul_of_the_Damned PRIVATE src)

target_link_libraries(Soul_of_the_Damned
    raylib
)
