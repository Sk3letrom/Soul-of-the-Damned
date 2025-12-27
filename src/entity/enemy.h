#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"

class Enemy : public Entity {

public:
    Enemy();

    int damageAmount;
    Rectangle rect;

    bool atack(Rectangle player, Rectangle enemy);
    void Update(float delta, bool onFloor, bool damage, int damageAmount) override;
    void Draw() override;



};




#endif