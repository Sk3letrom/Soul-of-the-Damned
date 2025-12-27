#include "consumables.h"
#include "entity/player.h"
#include <iostream>

Consumables::Consumables(ConsumableType type, int status, const std::string& name) 
    : type(type), status(status), name(name) {}

void Consumables::useConsumable(ConsumableType type, int status, Player& player) {
    switch (type) {
        case ConsumableType::HEALTH:
            if (player.health < player.maxHealth) player.health += status;
            if (player.health > player.maxHealth) player.health = player.maxHealth;
            break;
        case ConsumableType::MANA:
            std::cout << "Using " << name << " to restore " << status << " mana." << std::endl;
            break;
        case ConsumableType::STAMINA:
            std::cout << "Using " << name << " to restore " << status << " stamina." << std::endl;
            break;
        
    }
}