#include "Food.h"
#include "raylib.h"

Food::Food() : gen(rd()) {
    Update();
}

void Food::Update() {
    std::uniform_int_distribution<> randPosX(0, (800/50) - 1);
    posX = randPosX(gen) * 50 + 25;

    std::uniform_int_distribution<> randPosY(0, (600/50) - 1);
    posY = randPosY(gen) * 50 + 75;

}

void Food::Draw() const {
    DrawCircle(posX, posY, radius, GREEN);
}
