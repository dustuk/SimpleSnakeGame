#pragma once
#include <random>


class Food {
private:
    std::random_device rd;
    std::mt19937 gen;

    int posX{};
    int posY{};
    float radius = 15.0f;

public:
    Food();

    [[nodiscard]] float GetX() const {return static_cast<float>(posX);}

    [[nodiscard]] float GetY() const {return static_cast<float>(posY);}

    [[nodiscard]] float GetRadius() const {return radius;}

    void Restart() {Update();};

    void Update();
    void Draw() const;

};