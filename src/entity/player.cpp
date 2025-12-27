#include "player.h"
#include "raylib.h"
#include "core/input.h"
#include <iostream>

Player::Player() {
    // Initialize player properties
    position = {400.0f, 400.0f};
    width = 100.0f;
    height = 150.0f;
    speed = 0.0f;
    acceleration = 500.0f;
    maxSpeed = 200.0f;
    health = 20;
    stamina = 20;
    maxStamina = 20;    
    staminaRegenRate = 2.0f;
    shiftDuration = 0.0f;
    maxShiftDuration = 0.3f; // Maximum shift duration in seconds
    dashImpulse = 8.0f;
    rect = { position.x, position.y, width, height };
    spaceDuration = 0.0f;
    maxSpaceDuration = 0.07f;
    velY = 0.0f;
    jumpForce = 900.0f; // pixels per second impulse
    gravity = 1500.0f; // pixels per second^2
    imunityTimer = 3.0f; // imunity duration after taking damage
    imunity = 0.0f; // current imunity time
    rolling = false;
}
void Player::Update(float delta, bool onFloor, bool damage, int damageAmount) {
    Input input = Input();
    // ============ Input ============
    if (IsKeyDown(input.left)) {
        speed -= acceleration * delta;
    }
    else if (IsKeyDown(input.right)) {
        speed += acceleration * delta;
    } else {
        speed *= 0.9f; // Friction
    }
    // Vertical physics: velocity-based jump
    if (onFloor) {
        // If pressed this frame, give an upward impulse
        if (IsKeyPressed(input.jump)) {
            velY = -jumpForce;
        } else if (velY > 0.0f) {
            // Ensure we don't accumulate downward velocity while standing
            velY = 0.0f;
        }
    }

    // Apply gravity and integrate vertical velocity
    velY += gravity * delta;
    position.y += velY * delta;

    
    if (speed > maxSpeed) speed = maxSpeed;
    if (speed < -maxSpeed) speed = -maxSpeed;
    
    // Gerenciar duração do shift
    if (IsKeyDown(input.sprint) && shiftDuration > 0.0f && stamina >= 5 && onFloor) {
        // Aplicar velocidade aumentada enquanto shift está ativo
        position.x += speed * delta * dashImpulse;
        shiftDuration -= delta; // Decrementar duração
        if (shiftDuration < 0.0f) {
            shiftDuration = 0.0f;
            rolling = false; // Terminar shift quando a duração acabar
        }
    } else if (IsKeyPressed(input.sprint) && stamina >= 5 && onFloor) {
        // Iniciar shift quando a tecla é pressionada
        stamina -= 5; // reduce stamina
        rolling = true;
        shiftDuration = maxShiftDuration;
    } else {
        // Update position based on speed
        position.x += speed * delta;
    }

    // Keep rectangle in sync with position and size
    rect.x = position.x;
    rect.y = position.y;
    rect.width = width;
    rect.height = height;

    // Stamina regeneration
    if (stamina < maxStamina) {
        std::cout << "stamina: " << stamina << std::endl;
        stamina += staminaRegenRate * delta; // Regenerate stamina over time
        if (stamina > maxStamina) stamina = maxStamina;
    }
    // Attack input
    if (IsKeyPressed(input.attack)) {
        atacking = true;
    } else {
        atacking = false;
    }
    
    // Health Update
    if (damage && imunity <= 0.0f && rolling == false) {
        health -= damageAmount;
        imunity = imunityTimer; // reset imunity timer
    }
    else if (imunity > 0.0f) {
        imunity -= delta;
        if (imunity < 0.0f) imunity = 0.0f;
    }
    if (health < 0) health = 0;

}

void Player::Draw() {
    DrawRectangleRec(rect, BLUE);
}

