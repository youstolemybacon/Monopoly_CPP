//
// Created by zacka on 7/25/2024.
//

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"

class Space;

class Gameplay {
public:
    void turn();
    static void getSpaceMenu(Player* player, Space* space);

};



#endif //GAMEPLAY_H
