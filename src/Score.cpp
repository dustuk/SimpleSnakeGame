#include "Score.h"

void Score::Update(const std::vector<Rectangle>& snake) {
    score = snake.size();
}

void Score::Draw() const {
    DrawText(TextFormat("Score: %i", score), 0, 0, 40, YELLOW);
}


