#include "Score.h"
#include "raylib.h"
#include <fstream>

void Score::SaveScore() {
    std::ifstream iFile("../score.txt");
    if (iFile.is_open()) {
        iFile >> highestScore;
        iFile.close();
    }

    if (highestScore <= score) {
        std::ofstream oFile("../score.txt");
        if (oFile.is_open()) {
            oFile << score;
            oFile.close();
        }
    }

}

void Score::Reset() {
    score = 0;
    std::ofstream oFile("../score.txt");
    oFile << score;
    oFile.close();
}

void Score::Update() {
    ++score;

}

void Score::Draw() const {
    DrawText(TextFormat("Score: %i", score), 0, 0, 40, YELLOW);
    DrawText(TextFormat("Highest Score: %i", highestScore), 450, 0, 40, YELLOW);
}


