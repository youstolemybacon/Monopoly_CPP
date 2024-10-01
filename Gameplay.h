//
// Created by zacka on 7/25/2024.
//

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"

class Space;

class Gameplay {
private:
public:
    static void turn(Player* player);
    static void spaceMenu(Player* player);
    static void preRollMenu(Player* player);
};



#endif //GAMEPLAY_H
