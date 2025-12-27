#ifndef WEAPON_H
#define WEAPON_H
#include "raylib.h"
#include <iostream>

enum class WeaponType {
    SWORD,
    AXE,
    BOW
};

class Weapon {
public:
    Rectangle rect;

    Weapon(WeaponType wType, int wDamage, float wRange, float wAttackSpeed, std::string wName);
    WeaponType type;
    int damage;
    float range;
    float attackSpeed;
    std::string name;

    float height;
    float width;
    float rotation = 180.0f;
    bool isAttacking = false;

    void atack(float);
    void Update(float delta, Vector2 playerPos);
    void Draw();
};


#endif