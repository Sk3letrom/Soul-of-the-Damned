#include "raylib.h"
#include "entity/player.h"
#include "entity/entity.h"
#include "entity/enemy.h"
#include "combat/weapon.h"
#include "ui/HUD.h"
#include "ui/menu.h"
#include "ui/playing.h"
#include <iostream>

bool DamagePlayer;

enum class GameState {
    CONFIG,
    MENU,
    PLAYING
};
 // game logic update function
void updateGame(Enemy& enemy, Player& player, Rectangle floor, bool& onFloor) { 
    DamagePlayer = enemy.atack(enemy.rect, player.rect);
    // Simple gravity
    onFloor = CheckCollisionRecs(floor, player.rect);
    if (onFloor) {
        // Simple collision response: stop the player from falling through the floor
        player.position.y = floor.y - player.height;
    }
}

int main() {
    int screenWidth = 1280;
    int screenHeight = 720;

    GameState currentState = GameState::MENU;

    InitWindow(screenWidth, screenHeight, "Dark Souls 2D!");
    SetTargetFPS(60);


    // Initialize game objects
    bool onFloor;
    Player player = Player();
    Enemy enemy = Enemy();
    Camera2D camera = { 0 };
    HUD hud = HUD();
    GamePlaying gamePlaying = GamePlaying();
    Weapon sword = Weapon(WeaponType::SWORD, 5, 50.0f, 1.0f, "Basic Sword");
    Menu menu = Menu();

    Rectangle floor = {0.0f, 550.0f, (float)screenWidth, (float)(screenHeight - 550)};
    floor.y += 200.0f; // Adjust floor position

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();

        
 
        // -------------------- UPDATE --------------------
        if (currentState == GameState::MENU) {
            menu.UpdateMenu(delta);
            if (IsKeyPressed(KEY_ENTER) && menu.optionSelected == 0) {
                currentState = GameState::PLAYING;
            } else if (IsKeyPressed(KEY_ENTER) && menu.optionSelected == 1) {
                currentState = GameState::CONFIG;
            }
            if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)) {
                menu.optionSelected = (menu.optionSelected + 1) % 2; // Alterna entre 0 e 1
            }
        } else if (currentState == GameState::PLAYING) {
            updateGame(enemy, player, floor, onFloor);
            player.Update(delta, onFloor, DamagePlayer, enemy.damageAmount);
            sword.Update(delta, player.position);
            gamePlaying.CameraFollowPlayer(player.position, camera);
        }else if (currentState == GameState::CONFIG) {
            if (IsKeyPressed(KEY_BACKSPACE)) {
                currentState = GameState::MENU;
            }
            if (IsKeyPressed(KEY_F) && !IsWindowFullscreen()) {
                int actualMonitorWidth = GetMonitorWidth(GetCurrentMonitor());
                int actualMonitorHeight = GetMonitorHeight(GetCurrentMonitor());
                SetWindowSize(actualMonitorWidth, actualMonitorHeight);
                ToggleFullscreen();
            } else if(IsKeyPressed(KEY_F) && IsWindowFullscreen()) {
                ToggleFullscreen();
                SetWindowSize(screenWidth, screenHeight);
            }
        }
        // -------------------- DRAWING --------------------
    BeginDrawing(); // Start Drawing
        ClearBackground(DARKGRAY);

        switch (currentState) {
            case GameState::MENU:
            {
                menu.DrawMenu();
                break;
            }
            case GameState::PLAYING:
                hud.Draw(player.health, (int)player.stamina); // Draw HUD
                BeginMode2D(camera); //inicia o modo 2D com a câmera personalizada
                gamePlaying.DrawGame(player, enemy, sword, floor, delta, onFloor);
                EndMode2D(); // finaliza o modo 2D
                break;
            case GameState::CONFIG:
                menu.DrawConfigMenu();
                break;
        }

        
        
        
        
        

        
        
    EndDrawing(); // End Drawing
        // -----------------------------
    }

    CloseWindow();
    return 0;
}
