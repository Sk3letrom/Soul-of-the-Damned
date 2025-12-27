#ifndef PLAYING_H
#define PLAYING_H
#include "raylib.h"
#include "entity/player.h"
#include "entity/enemy.h"
#include "combat/weapon.h"

class GamePlaying {
public:
    void CameraFollowPlayer(Vector2 playerPos, Camera2D &camera);
    void DrawGame( Player& player, Enemy& enemy, Weapon& sword, Rectangle& floor, float delta);
};

#endif