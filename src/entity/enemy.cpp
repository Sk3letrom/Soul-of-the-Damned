#include "enemy.h"
#include "raylib.h"
#include <iostream>

Enemy::Enemy() {
    // Initialize enemy properties
    position = {100.0f, 550.0f};
    width = 150.0f;
    height = 150.0f;
    speed = 0.0f;
    acceleration = 300.0f;
    maxSpeed = 150.0f;
    health = 10;
    stamina = 10;
    rect = { position.x, position.y, width, height };
    damageAmount = 2;
}

bool Enemy::atack(Rectangle player, Rectangle enemy) {
    // Enemy attack logic
    if (CheckCollisionRecs(player, enemy)) {
        return true;
    } else {
        return false;
    }
}

void Enemy::Update(float delta, bool onFloor, bool damage, int damageAmount) {
    // Simple AI movement towards the right
    speed += acceleration * delta;
    if (speed > maxSpeed) speed = maxSpeed;
    position.x += speed * delta;
}

void Enemy::Draw() {
    DrawRectangleRec(rect, RED);
}