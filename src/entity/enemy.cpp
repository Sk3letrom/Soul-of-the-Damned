#include "enemy.h"
#include "player.h"
#include "raylib.h"
#include <iostream>
#include <cmath>

Enemy::Enemy(EnemyType type) {
    // ===========================Initialize enemy properties ==============================
    position = {100.0f, 550.0f};
    startChase = false;
    gravity = 1500.0f; // pixels per second^2;
    velY = 0.0f;
    player = nullptr; // Initialize to null
    
    switch (type) {
        case Minion:
            width = 50.0f;
            height = 50.0f;
        
            speed = 0.0f;
            acceleration = 200.0f;
            maxSpeed = 100.0f;
        
            health = 5;
            stamina = 5;
        
            damageAmount = 1;
            engageDistance = 200.0f;
            disengageDistance = 250.0f;
        break;
        case Normal:
            width = 150.0f;
            height = 150.0f;
        
            speed = 0.0f;
            acceleration = 300.0f;
            maxSpeed = 150.0f;
        
            health = 10;
            stamina = 10;
        
            damageAmount = 2;
            engageDistance = 300.0f;
            disengageDistance = 350.0f;
        break;
        case Elite:
            width = 200.0f;
            height = 200.0f;
            
            speed = 0.0f;
            acceleration = 400.0f;
            maxSpeed = 200.0f;

            health = 20;
            stamina = 20;

            damageAmount = 4;
            engageDistance = 400.0f;
            disengageDistance = 450.0f;
            break;
        case Boss:
            width = 300.0f;
            height = 300.0f;
            
            speed = 0.0f;
            acceleration = 500.0f;
            maxSpeed = 250.0f;

            health = 50;
            stamina = 50;

            damageAmount = 10;
            engageDistance = 500.0f;
            disengageDistance = 600.0f;
            break;
    }
    rect = { position.x, position.y, width, height };

}

void Enemy::setPlayer(Player* playerRef) {
    player = playerRef;
}

bool Enemy::atack(Rectangle player, Rectangle enemy) {
    // Enemy attack logic
    if (CheckCollisionRecs(player, enemy)) {
        return true;
    } else {
        return false;
    }
}

void Enemy::Update(float delta, bool damage, int damageAmount, Rectangle floor) {
    
    if (!player) return; // Safety: player reference not set

    // dx is a simple distance check on x axis
    float dx = std::fabs(player->position.x - position.x);

    if (!startChase && dx <= engageDistance) {
        startChase = true;
        std::cout << "Começou a perseguir\n";
    } else if (startChase && dx > disengageDistance) {
        startChase = false;
        speed = 0.0f; // stop when abandoning chase
        std::cout << "Parou de perseguir\n";
    }

    // ================== Gravity effect ==================
    velY += gravity * delta;
    position.y += velY * delta;
    
    // Update rectangle position temporarily to check collision
    rect.y = position.y;
    rect.x = position.x;
    
    // Check collision with floor
    if (CheckCollisionRecs(rect, floor)) {
        // Snap to top of floor
        position.y = floor.y - height;
        velY = 0.0f; // Reset vertical velocity when on ground
        onFloor = true;
    } else {
        onFloor = false;
    }

    // Update rectangle position to match corrected entity position
    rect.y = position.y;
    rect.x = position.x;
}

void Enemy::ChasePlayer(float delta, Vector2 playerPosition, bool collidingWithPlayer) {
    if (!collidingWithPlayer && startChase) {
        if (playerPosition.x < position.x) {
            // Move left towards player
            speed -= acceleration * delta;
            if (speed < -maxSpeed) speed = -maxSpeed;
        } else if (playerPosition.x > position.x) {
            // Move right towards player
            speed += acceleration * delta;
            if (speed > maxSpeed) speed = maxSpeed;
        }
        position.x += speed * delta;
    } else if (collidingWithPlayer) {
        speed = 0.0f; // Stop moving when colliding
    }

    // Update rectangle position to match entity position
    rect.x = position.x;
    rect.y = position.y;
}

void Enemy::Draw() {
    DrawRectangleRec(rect, RED);
}