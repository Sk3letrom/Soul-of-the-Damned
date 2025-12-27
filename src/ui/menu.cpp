#include "menu.h"
#include "raylib.h"
#include <iostream>

void Menu::UpdateMenu(float delta) {
    switch (optionSelected) {
        case 0:
            OptionSelected1 = {130, 130, 130, 255}; // Reset Config option color
            // Start Game option selected - pulsating effect
            RGB += rgbDirection * 100 * delta; // 100 unidades por segundo
            
            if (RGB >= 170) {
                RGB = 170;
                rgbDirection = -1; // Inverte para diminuir
            } else if (RGB <= 80) {
                RGB = 80;
                rgbDirection = 1; // Inverte para aumentar
            }
            
            OptionSelected0 = {static_cast<unsigned char>(RGB), static_cast<unsigned char>(RGB), static_cast<unsigned char>(RGB), 255};
            break;
        case 1:
            OptionSelected0 = {130, 130, 130, 255}; // Reset Start option color
            // Config option selected
            RGB += rgbDirection * 100 * delta; // 100 unidades por segundo
            
            if (RGB >= 170) {
                RGB = 170;
                rgbDirection = -1; // Inverte para diminuir
            } else if (RGB <= 80) {
                RGB = 80;
                rgbDirection = 1; // Inverte para aumentar
            }
            
            OptionSelected1 = {static_cast<unsigned char>(RGB), static_cast<unsigned char>(RGB), static_cast<unsigned char>(RGB), 255};
            break;    
    }
}

void Menu::DrawConfigMenu() {
    DrawText("Config Menu - Press BACKSPACE to return", 400, 100, 20, WHITE);
    if (IsWindowFullscreen()) DrawRectangle(20, 20 , 200, 50, GREEN); 
    else DrawRectangle(20, 20 , 200, 50, RED);
    DrawText("Toggle Fullscreen (F)", 30, 35, 15, WHITE);
}

void Menu::DrawMenu() {
    DrawText("Dark Souls 2D", 500, 100, 40, WHITE);
    DrawText("Press ENTER to Start", 500, 200, 20, WHITE);

    DrawRectangle(GetScreenWidth()/2 - 100, GetScreenHeight()/2 - 25, 200, 50, OptionSelected0);
    DrawText("START", GetScreenWidth()/2 - 30, GetScreenHeight()/2 - 10, 20, WHITE);

    DrawRectangle(GetScreenWidth()/2 - 100, GetScreenHeight()/2 + 50, 200, 50, OptionSelected1);
    DrawText("CONFIG", GetScreenWidth()/2 - 20, GetScreenHeight()/2 + 65, 20, WHITE);
}