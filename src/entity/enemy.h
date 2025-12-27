#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"

class Player; // Forward declaration to avoid circular dependency with player.h

enum EnemyType {
    Minion,
    Normal,
    Elite,
    Boss
};

class Enemy : public Entity {

public:
    Enemy(EnemyType type);

    bool onFloor;

    float engageDistance; // Distance to start chasing
    float disengageDistance; // Distance to stop chasing

    int damageAmount;
    bool startChase;
    Player* player; // Pointer to the player object for tracking

    Rectangle rect;

    void setPlayer(Player* playerRef);

    bool atack(Rectangle player, Rectangle enemy);
    void Update(float delta, bool damage, int damageAmount, Rectangle floor) override;
    void ChasePlayer(float delta, Vector2 playerPosition, bool collidingWithPlayer);
    void Draw() override;

private:
    float velY;
};




#endif