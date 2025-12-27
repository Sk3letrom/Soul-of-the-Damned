#include "playing.h"
#include "entity/enemy.h"
#include "entity/player.h"
#include "combat/weapon.h"
#include "raylib.h"

void GamePlaying::CameraFollowPlayer(Vector2 playerPos, Camera2D &camera) {
    Vector2 targetDelay = { playerPos.x - camera.target.x, playerPos.y - camera.target.y };
    camera.target.x += targetDelay.x * 0.1f; // Smooth follow factor
    camera.target.y += targetDelay.y * 0.1f;
    camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void GamePlaying::DrawGame( Player& player, Enemy& enemy, Weapon& sword, Rectangle& floor, float delta, bool onFloor) {
    player.Draw();
    
    if (player.atacking) sword.atack(delta);
    
    sword.Draw();

    DrawRectangleRec(floor, BROWN);
    enemy.Update(delta, onFloor, false, 0);
    enemy.Draw();
}