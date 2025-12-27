#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"
#include <vector>
#include "combat/consumables.h"

class Player : public Entity {

public:
    Player();
    
    float imunityTimer;
    float imunity;
    bool rolling;
    float dashImpulse;

    bool onFloor;

    Rectangle rect;

    bool atacking;

    void Update(float delta, bool damage, int damageAmount, Rectangle floor) override;
    void UseConsumable(std::vector<Consumables>& healPotions);
    void inventoryManagement(std::vector<Consumables>& healPotions);
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