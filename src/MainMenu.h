#pragma once
#include <raylib.h>
#include <vector>
#include "Score.h"

class MainMenu {
private:
    bool isInMainMenu = true;
    bool shouldClose = false;

    float windowWidth{};
    float windowHeight{};
    const int fontSize = 30;
    const float btnWidth = 200;
    const float btnHeight = 50;
    const float gap = 15.0f;


    enum class MenuAction {
        Start,
        ResetScore,
        Exit
    };

    struct ButtonItem {
        const char* text;
        Rectangle bounds;
        MenuAction action;
    };

    std::vector<ButtonItem> btns;

public:
    MainMenu() = default;

    [[nodiscard]] bool GetIsMainMenu() const {return isInMainMenu;}

    void Restart() {isInMainMenu = true;}
    [[nodiscard]] bool ShouldClose() const { return shouldClose;}

    [[nodiscard]] Rectangle BtnBounds() const;
    [[nodiscard]] static bool IsHovered(Rectangle btnBounds);

    void ClaimWindowSizes(int width, int height);

    void DrawBtn() const;

    void Update(Score& score);
    void Draw() const;
};
