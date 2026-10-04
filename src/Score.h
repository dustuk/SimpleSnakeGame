#pragma once
#include <vector>
#include "raylib.h"

class Score {
private:
    size_t score{};

public:
    Score() = default;

    void Update(const std::vector<Rectangle>& snake);
    void Draw() const;
};
