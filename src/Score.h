#pragma once

class Score {
private:
    int score = 0;
    int highestScore{};

public:
    Score() = default;

    void SaveScore();

    void Reset();

    void Update();
    void Draw() const;
};
