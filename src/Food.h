#pragma once
#include "Player.h"
#include <random>


class Food {
private:
    std::random_device rd;

    int posX = 75;
    int posY = 75;

    Player player;
public:
    Food() = default;

    void Pos();

    void Update();
    void Draw() const;
};