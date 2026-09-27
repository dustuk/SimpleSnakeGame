cmake_minimum_required(VERSION 4.3)
project(SimpleSnakeGame)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)


set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(SimpleSnakeGame src/main.cpp
        src/Game.cpp
        src/Game.h
)
target_link_libraries(SimpleSnakeGame PRIVATE raylib)