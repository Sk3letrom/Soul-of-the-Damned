#include "weapon.h"
#include "raylib.h"
#include "entity/player.h"
#include <iostream>

Weapon::Weapon(WeaponType wType, int wDamage, float wRange, float wAttackSpeed, std::string wName) {
    type = wType;
    damage = wDamage;
    range = wRange;
    attackSpeed = wAttackSpeed;
    name = wName;

}

void Weapon::Update(float delta, Vector2 playerPos) {
    if (type == WeaponType::SWORD) {
        height = 100.0f;
        width = 40.0f;
    }
    rect.x = playerPos.x + 140.0f;
    rect.y = playerPos.y + 40.0f;

    rect = { rect.x, rect.y, width, height };

    // Advance attack animation per frame when attacking
    if (isAttacking) {
        // Adjust multiplier (500.0f) to tune speed. Higher = faster.
        rotation += (attackSpeed * 500.0f) * delta;
        if (rotation >= 315.0f) {
            rotation = 180.0f;
            isAttacking = false;
        }
    }
}

void Weapon::atack(float delta) {
    isAttacking = true;
}

void Weapon::Draw() {
    DrawRectanglePro(rect, {0.0f, 0.0f}, rotation, GREEN);
}