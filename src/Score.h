#pragma once

class Score {
private:
    int score = 0;
    int highestScore{};

    const char* path = "score.txt";

public:
    Score() = default;

    void SaveScore();

    void ResetScore() {score = 0;}
    void ResetHighestScore() const;

    [[nodiscard]] int GetScore() const {return score;}

    void Update();
    void Draw() const;
};
