#pragma once
#include "raylib.h"
#include "Player.h"

class Game {
private:
    const int windowWidth;
    const int windowHeight;

    Player player;

public:
    Game(int width, int height, const char* title);
    ~Game();

    static void DrawGrid2D(int startX, int startY, int cols, int rows, int cellSize, Color color);

    void Run();

};
