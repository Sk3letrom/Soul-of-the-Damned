#ifndef ENTITY_H
#define ENTITY_H
#include "raylib.h"

class Entity {

public:
     Vector2 position;
    float width;
    float height;
    float speed;
    float acceleration;
    float maxSpeed;
    int health;
    int maxHealth;
    float stamina;
    float maxStamina;
    float staminaRegenRate;
    float gravity;
    //animation
    int framesCounter;
    float framesSpeed;
    int currentFrame;
    Rectangle currentFrameRec;

    Entity();
                                                                   //floor is temporary, will be removed later
    virtual void Update(float delta, bool damage, int damageAmount, Rectangle floor) = 0; // Pure virtual function for updating the entity
    virtual void Draw() = 0; // Pure virtual function for drawing the entity
    virtual void Animation() = 0; // Pure virtual function for animation


};


#endif