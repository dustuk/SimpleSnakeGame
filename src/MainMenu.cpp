#include "MainMenu.h"
#include "raylib.h"

void MainMenu::Update() {
    if (IsKeyPressed(KEY_SPACE)) {
        isInMainMenu = false;
    }
}

void MainMenu::Draw() const {
    ClearBackground(DARKGRAY);

    int textWidth = MeasureText(text, fontSize);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (screenHeight - fontSize) / 2;

    DrawText(text, textX, textY, fontSize, YELLOW);
}
