#include "Player.h"

Player::Player() {
    snake.push_back(Rectangle{posX, posY, playerWidth, playerHeight});
}

void Player::Graw() {
    snake.push_back(snake.back());
}

void Player::Update() {
    if (IsKeyPressed(KEY_W) && currentDirection != Directions::Down) direction = Directions::Up;
    if (IsKeyPressed(KEY_D) && currentDirection != Directions::Left) direction = Directions::Right;
    if (IsKeyPressed(KEY_S) && currentDirection != Directions::Up)   direction = Directions::Down;
    if (IsKeyPressed(KEY_A) && currentDirection != Directions::Right) direction = Directions::Left;


    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= moveInterval) {


        for (size_t i = snake.size() - 1; i > 0; --i) {
            snake[i].x = snake[i - 1].x;
            snake[i].y = snake[i - 1].y;
        }

        if (direction == Directions::Up) snake[0].y -= moveSpeed;
        if (direction == Directions::Right) snake[0].x += moveSpeed;
        if (direction == Directions::Down) snake[0].y += moveSpeed;
        if (direction == Directions::Left) snake[0].x -= moveSpeed;

        currentDirection = direction;

        if (snake[0].x >= windowWidth) {
            snake[0].x = 0;
        } else if (snake[0].x < 0) {
            snake[0].x = windowWidth  - gridSize;
        }

        if (snake[0].y >= windowHeight) {
            snake[0].y = 50;
        } else if (snake[0].y < 50) {
            snake[0].y = windowHeight - gridSize;
        }

        lastUpdateTime = currentTime;
    }
}

void Player::Draw() const {
    for (const auto&  segment : snake) {
        DrawRectangleRec(segment, RED);
    }
}


