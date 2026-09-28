cmake_minimum_required(VERSION 4.3)
project(SimpleSnakeGame)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(SimpleSnakeGame
        src/main.cpp
        src/Game.cpp
        src/Game.h
)

target_link_libraries(SimpleSnakeGame PRIVATE raylib)