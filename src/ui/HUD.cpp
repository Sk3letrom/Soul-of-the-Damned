#include "HUD.h"
#include "raylib.h"

void HUD::Draw(int health, int stamina) {
    // Draw Health Bar
    DrawRectangle(20, 20, 200, 20, RED);
    DrawRectangle(20, 20, (int)(200 * ((float)health / 20.0f)), 20, GREEN);

    // Draw Stamina Bar
    DrawRectangle(20, 70, 200, 20, GRAY);
    DrawRectangle(20, 70, (int)(200 * (stamina / 20.0f)), 20, BLUE);
}
