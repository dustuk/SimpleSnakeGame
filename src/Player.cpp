#include "Player.h"

void Player::Update() {
    if (IsKeyPressed(KEY_W) && currentDirection != Directions::Down) direction = Directions::Up;
    if (IsKeyPressed(KEY_D) && currentDirection != Directions::Left) direction = Directions::Right;
    if (IsKeyPressed(KEY_S) && currentDirection != Directions::Up)   direction = Directions::Down;
    if (IsKeyPressed(KEY_A) && currentDirection != Directions::Right) direction = Directions::Left;


    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= moveInterval) {
        if (direction == Directions::Up) posY -= moveSpeed;
        if (direction == Directions::Right) posX += moveSpeed;
        if (direction == Directions::Down) posY += moveSpeed;
        if (direction == Directions::Left) posX -= moveSpeed;

        currentDirection = direction;
        lastUpdateTime = currentTime;
    }
}

void Player::Draw() const {
    DrawRectangle(static_cast<int>(posX), static_cast<int>(posY), playerWidth, playerHeight, RED);
}
