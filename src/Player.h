#include "raylib.h"
#pragma once  
#include <vector>


class Player {
private:
    float posX = 100.0f;
    float posY = 0.0f;
    const float playerWidth = 50.0f;
    const float playerHeight = 50.0f;

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

    std::vector<Rectangle> snake;

public:
    Player();

    void Graw();

    [[nodiscard]] float GetPosX() const {return posX;};
    [[nodiscard]] float GetPosY() const {return posY;};

    void  Update();
    void Draw() const;
};