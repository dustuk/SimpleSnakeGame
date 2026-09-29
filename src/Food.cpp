#include "Food.h"

void Food::Pos() {
    std::mt19937 gen(Food::rd());
    std::uniform_int_distribution<> randPosX(0, (600/50) - 1);
    posX = randPosX(gen) * 50 + 25;

    std::uniform_int_distribution<> randPosY(0, (800/50) - 1);
    posY = randPosY(gen) * 50 + 25;

}


void Food::Update() {
    if (static_cast<float>(posX) == player.GetPosX() && static_cast<float>(posY) == player.GetPosY()) {
        Pos();
    }


}

void Food::Draw() const {
    DrawCircle(posX, posY, 15.0f, GREEN);
}
