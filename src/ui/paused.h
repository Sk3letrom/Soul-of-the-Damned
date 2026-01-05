#ifndef PAUSED_H
#define PAUSED_H
#include "raylib.h"

class Paused {
public:
    Paused();
    float windowWidth;
    float windowHeight;

    void UpdatePaused(float delta);
    void DrawPaused();
};



#endif