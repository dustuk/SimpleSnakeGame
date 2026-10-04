#pragma once
#include "raylib.h"
#include <vector>

class Player {
private:
    float posX = 400.0f;
    float posY = 300.0f;
    const float playerWidth = 50.0f;
    const float playerHeight = 50.0f;

    const float moveSpeed = 50.0f;
    const float moveInterval = 0.2f;
    double lastUpdateTime = 0.0;


    const float gridSize = 50.0f;
    const float windowWidth = 800.0f;
    const float windowHeight = 650.0f;

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

    [[nodiscard]] std::vector<Rectangle>& GetSnake() {return snake;}

    void Restart() {snake.clear(); snake.push_back(Rectangle{posX, posY, playerWidth, playerHeight});}

    void Update();
    void Draw() const;
};
