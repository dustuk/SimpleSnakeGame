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
    float windowWidth{};
    float windowHeight{};

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

    [[nodiscard]] const std::vector<Rectangle>& GetSnake() const {return snake;}

    void ClaimWindowSizes(int width, int height) {windowWidth = static_cast<float>(width); windowHeight = static_cast<float>(height);}

    void Restart() {snake.clear(); snake.push_back(Rectangle{posX, posY, playerWidth, playerHeight});}

    void Update();
    void Draw() const;
};
