#include "Game.h"

Game::Game(int width, int height, const char* title) : windowWidth(width), windowHeight(height) {
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(60);
    player.ClaimWindowSizes(width, height);
    mainMenu.ClaimWindowSizes(width, height);
}

Game::~Game() {
    CloseWindow();
}



void Game::CheckRestart() {
    if (player.GetSnake().size() > 4) {
        for (int i = 1; i < player.GetSnake().size(); ++i) {
            if (player.GetSnake()[0].x == player.GetSnake()[i].x && player.GetSnake()[0].y == player.GetSnake()[i].y) {
                WaitTime(0.5);
                mainMenu.Restart();
                player.Restart();
                food.Restart();
                break;
            }
        }
    }
}

void Game::CheckPlayerFoodCollision() {
    if (CheckCollisionCircleRec(Vector2{food.GetX(), food.GetY()}, food.GetRadius(), player.GetSnake()[0])) {
        food.Restart();
        player.Graw();
        score.Update();
    }
}

void Game::DrawGrid2D(int startX, int startY, int cols, int rows, int cellSize, Color color) {
    startY += 50;
    for (int i = 0; i <= rows; i++)
        DrawLine(startX, startY + i * cellSize, startX + cols * cellSize, startY + i * cellSize, color);

    for (int i = 0; i <= cols; i++)
        DrawLine(startX + i * cellSize, startY, startX + i * cellSize, startY + rows * cellSize, color);
}

void Game::Run() {
    while (!WindowShouldClose()) {
        mainMenu.Update(score);

        if (mainMenu.ShouldClose()) break;

        if (!mainMenu.GetIsMainMenu()) {
            player.Update();
            score.SaveScore();
            CheckPlayerFoodCollision();
            CheckRestart();

            BeginDrawing();
            ClearBackground(DARKGRAY);

            player.Draw();
            score.Draw();
            food.Draw();

            DrawGrid2D(0, 0, cols, rows, 50, GRAY);
            EndDrawing();
        } else {
            BeginDrawing();
            mainMenu.Draw();
            EndDrawing();
        }
    }
}
