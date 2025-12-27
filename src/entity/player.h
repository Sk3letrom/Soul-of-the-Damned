#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

class Player : public Entity {

public:
    Player();
    
    float imunityTimer;
    float imunity;
    bool rolling;
    float dashImpulse;

    Rectangle rect;

    bool atacking;

    void Update(float delta, bool onFloor, bool damage, int damageAmount) override;
    void Draw() override;

private:
    float shiftDuration;
    float maxShiftDuration;
    float spaceDuration;
    float maxSpaceDuration;
    // Vertical physics
    float velY;
    float jumpForce;
};


#endif