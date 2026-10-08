#include "MainMenu.h"


void MainMenu::ClaimWindowSizes(int width, int height) {
    windowWidth = static_cast<float>(width);
    windowHeight = static_cast<float>(height);

    btns.clear();
    btns.emplace_back("Start", BtnBounds(), MenuAction::Start);
    btns.emplace_back("Reset Score", BtnBounds(), MenuAction::ResetScore);
    btns.emplace_back("Exit", BtnBounds(), MenuAction::Exit);


    float currentOffset = 0.0f;
    for (auto &btn: btns) {
        btn.bounds.y += currentOffset;
        currentOffset += (btn.bounds.height + gap);
    }
}

Rectangle MainMenu::BtnBounds() const {
    float posX = (windowWidth - btnWidth) / 2;
    float posY = (windowHeight - btnHeight) / 2 - 50;
    Rectangle bounds = {posX, posY, btnWidth, btnHeight};
    return bounds;
}

bool MainMenu::IsHovered(Rectangle btnBounds) {
    return CheckCollisionPointRec(GetMousePosition(), btnBounds);
}

void MainMenu::DrawBtn() const {
    for (const auto& btn : btns) {
        Color btnColor = IsHovered(btn.bounds) ? GOLD : YELLOW;
        DrawRectangleRec(btn.bounds, btnColor);

        int textWidth = MeasureText(btn.text, fontSize);
        int textX = static_cast<int>(btn.bounds.x) + (static_cast<int>(btn.bounds.width) - textWidth) / 2;
        int textY = static_cast<int>(btn.bounds.y) + (static_cast<int>(btn.bounds.height) - fontSize) / 2;

        DrawText(btn.text, textX, textY, fontSize, GRAY);
    }
}

void MainMenu::Update(Score& score) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (const auto& btn : btns) {
            if (IsHovered(btn.bounds)) {
                switch (btn.action) {
                    case MenuAction::Start:
                        isInMainMenu = false;
                        break;
                    case MenuAction::ResetScore:
                        score.Reset();
                        break;
                    case MenuAction::Exit:
                        shouldClose = true;
                        break;
                }
                break;
            }
        }
    }
}

void MainMenu::Draw() const {
    ClearBackground(DARKGRAY);

    DrawBtn();
}
