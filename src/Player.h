#pragma once
#include "raylib.h"


class Player {
private:
    float posX = 100.0f;
    float posY = 0.0f;
    const int playerWidth = 50;
    const int playerHeight = 50;

    const float moveSpeed = 50.0f;
    const float moveInterval = 0.2f;
    double lastUpdateTime = 0.0;

    enum class Directions {
        Up,
        Right,
        Down,
        Left
    };

    Directions direction = Directions::Right;
    Directions currentDirection = Directions::Right;

public:
    Player() = default;

    void  Update();
    void Draw() const;
};
