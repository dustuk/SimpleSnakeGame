#pragma once
#include "Player.h"
#include "Food.h"
#include "MainMenu.h"
#include "Score.h"

class Game {
private:
    int windowWidth, windowHeight;

    const int cols = windowWidth/50;
    const int rows = (windowHeight - 50)/50;

    Player player;
    Food food;
    MainMenu mainMenu;
    Score score;

public:
    Game(int width, int height, const char* title);
    ~Game();

    void CheckRestart();
    void CheckPlayerFoodCollision();
    void RespawnFoodSafely();

    static void DrawGrid2D(int startX, int startY, int cols, int rows, int cellSize, Color color);

    void Run();

};
