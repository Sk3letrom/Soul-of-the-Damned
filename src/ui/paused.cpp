#include "paused.h"
#include "raylib.h"

Paused::Paused() {
    windowWidth = static_cast<float>(GetScreenWidth());
    windowHeight = static_cast<float>(GetScreenHeight());
}

void Paused::UpdatePaused(float delta) {
    windowWidth = static_cast<float>(GetScreenWidth());
    windowHeight = static_cast<float>(GetScreenHeight());
}

void Paused::DrawPaused() {
    DrawRectangle(0, 0, static_cast<int>(windowWidth), static_cast<int>(windowHeight), {0, 0, 0, 150});
    
    DrawText("Game Paused", static_cast<int>(windowWidth / 2) - 100, static_cast<int>(windowHeight / 2) - 20, 20, WHITE);
    DrawText("Press ESC to Resume", static_cast<int>(windowWidth / 2) - 130, static_cast<int>(windowHeight / 2) + 20, 20, WHITE);
}