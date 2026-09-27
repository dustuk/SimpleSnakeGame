#include "Game.h"

Game::Game(int width, int height, const char* title) : windowWidth(width), windowHeight(height) {
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(60);
}

Game::~Game() {
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DARKGRAY);
        EndDrawing();
    }
}
