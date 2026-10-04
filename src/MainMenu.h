#pragma once

class MainMenu {
private:
    bool isInMainMenu = true;

    const int screenWidth = 800;
    const int screenHeight = 600;
    const char* text = "Press Space to start";
    const int fontSize = 40;


public:
    MainMenu() = default;

    [[nodiscard]] bool GetIsMainMenu() const {return isInMainMenu;}

    void Restart() {isInMainMenu = true;}

    void Update();
    void Draw() const;
};
