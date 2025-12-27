#include "input.h"
#include "raylib.h"

Input::Input() {
    // movement keys
    jump = KEY_SPACE;
    left = KEY_A;
    right = KEY_D;
    // action keys
    attack = KEY_K;
    sprint = KEY_LEFT_SHIFT;
    heal = KEY_H;
    pickup = KEY_E;
}