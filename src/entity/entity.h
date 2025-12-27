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
    float stamina;
    float maxStamina;
    float staminaRegenRate;
    float gravity;

    Entity();

    virtual void Update(float delta, bool onFloor, bool damage, int damageAmount) = 0; // Pure virtual function for updating the entity
    virtual void Draw() = 0; // Pure virtual function for drawing the entity


};


#endif