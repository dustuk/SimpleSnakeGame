#include "Game.h"

Game::Game(int width, int height, const char* title) : windowWidth(width), windowHeight(height) {
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(60);
}

Game::~Game() {
    CloseWindow();
}

void Game::DrawGrid2D(int startX, int startY, int cols, int rows, int cellSize, Color color) {
    for (int i = 0; i <= rows; i++)
        DrawLine(startX, startY + i * cellSize, startX + cols * cellSize, startY + i * cellSize, color);

    for (int i = 0; i <= cols; i++)
        DrawLine(startX + i * cellSize, startY, startX + i * cellSize, startY + rows * cellSize, color);
}

void Game::Run() {
    while (!WindowShouldClose()) {
        player.Update();

        BeginDrawing();

        player.Draw();

        DrawGrid2D(0, 0, 16, 12, 50, GRAY);

        ClearBackground(DARKGRAY);
        EndDrawing();
    }
}
