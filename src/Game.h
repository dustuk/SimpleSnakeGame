#pragma once
#include "raylib.h"

class Game {
private:
    const int windowWidth;
    const int windowHeight;

public:
    Game(int width, int height, const char* title);
    ~Game();

    void Run();

};
