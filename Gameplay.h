//
// Created by zacka on 7/25/2024.
//

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"

class Space;

class Gameplay {
private:
    enum class PreRollMenuOptions
    {
        ROLL = 1,
        DEVELOP_PROPERTIES,
        TRADE,
        MORTGAGE
    };
public:
    void turn(Player* player);
    static void spaceMenu(Player* player);
    static void preRollMenu(Player* player);
};



#endif //GAMEPLAY_H
