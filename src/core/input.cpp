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
}