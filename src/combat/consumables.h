#ifndef CONSUMABLES_H
#define CONSUMABLES_H
#include <iostream>

class Player; // Forward declaration to avoid circular dependency with player.h

enum class ConsumableType {
    HEALTH,
    MANA,
    STAMINA

};

class Consumables {
public:
    Consumables(ConsumableType type, int status, const std::string& name);

    ConsumableType type;
    int status;
    std::string name;

    void useConsumable(ConsumableType type, int status, Player& player);
};


#endif