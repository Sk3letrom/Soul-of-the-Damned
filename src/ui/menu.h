#ifndef MENU_H
#define MENU_H
#include "raylib.h"

class Menu {
public:
    int RGB = 130;
    int rgbDirection = 1; // 1 para aumentar, -1 para diminuir
    Color OptionSelected0 = {static_cast<unsigned char>(RGB), static_cast<unsigned char>(RGB), static_cast<unsigned char>(RGB), 255};
    Color OptionSelected1 = {static_cast<unsigned char>(RGB), static_cast<unsigned char>(RGB), static_cast<unsigned char>(RGB), 255};
    int optionSelected = 0;
    void UpdateMenu(float delta);
    void DrawConfigMenu();
    
    void DrawMenu();
};



#endif