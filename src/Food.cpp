#include "Food.h"
#include "raylib.h"

Food::Food() : gen(rd()) {}

void Food::SetupFood() {
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight() - 50;
    Update();
}

void Food::Update() {
    std::uniform_int_distribution<> randPosX(0, (windowWidth/50) - 1);
    posX = randPosX(gen) * 50 + 25;

    std::uniform_int_distribution<> randPosY(0, (windowHeight/50) - 1);
    posY = randPosY(gen) * 50 + 75;

}

void Food::Draw() const {
    DrawCircle(posX, posY, radius, GREEN);
}
