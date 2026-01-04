#include "raylib.h"
#include "entity/player.h"
#include "entity/entity.h"
#include "entity/enemy.h"
#include "combat/weapon.h"
#include "ui/HUD.h"
#include "ui/menu.h"
#include "ui/playing.h"
#include "combat/consumables.h"
#include <iostream>
#include <vector>

bool DamagePlayer;

enum class GameState {
    CONFIG,
    MENU,
    PLAYING
};
 // game logic update function
void updateGame(Enemy& enemy, Player& player) {
     // Check collision between enemy and player
    DamagePlayer = enemy.atack(enemy.rect, player.rect);
}

std::vector<Texture2D> LoadTextures() {
    std::vector<Texture2D> playerTextures;
    playerTextures.push_back(LoadTexture("../assets/resources/player/player_stop_128-Sheet.png"));
    playerTextures.push_back(LoadTexture("../assets/resources/player/player_walking_right-Sheet.png"));

    return playerTextures;
}

void UnloadTextures(std::vector<Texture2D>& textures) {
    for (auto& texture : textures) {
        UnloadTexture(texture);
    }
}

int main() {
    int screenWidth = 1280;
    int screenHeight = 720;

    GameState currentState = GameState::MENU;

    InitWindow(screenWidth, screenHeight, "Dark Souls 2D!");
    SetTargetFPS(60);

    std::vector<Texture2D> playerTextures = LoadTextures();

    // ============ Initialize game objects ============
    Player player = Player(playerTextures);
    Enemy enemy = Enemy(EnemyType::Normal);
    enemy.setPlayer(&player); // Set player reference to avoid nullptr crash
    Camera2D camera = { 0 };
    HUD hud = HUD();
    GamePlaying gamePlaying = GamePlaying();
    Weapon sword = Weapon(WeaponType::SWORD, 5, 50.0f, 1.0f, "Basic Sword");
    Menu menu = Menu();

    std::vector<Consumables> healPotions;
    // ================================================

    Rectangle floor = {0.0f, 550.0f, (float)(screenWidth + 1000), (float)(screenHeight - 550)};
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
            updateGame(enemy, player);
        
            player.Update(delta, DamagePlayer, enemy.damageAmount, floor);
            player.inventoryManagement(healPotions);
            player.UseConsumable(healPotions);
            
            enemy.ChasePlayer(delta, player.position, DamagePlayer);
            enemy.Update(delta, false, 0, floor);

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
                gamePlaying.DrawGame(player, enemy, sword, floor, delta);
                EndMode2D(); // finaliza o modo 2D
                break;
            case GameState::CONFIG:
                menu.DrawConfigMenu();
                break;
        }

        
        
        
        
        

        
        
    EndDrawing(); // End Drawing
        // -----------------------------
    }

    UnloadTextures(playerTextures); // Unload all loaded textures

    CloseWindow();
    return 0;
}
