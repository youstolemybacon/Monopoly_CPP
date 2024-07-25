//
// Created by zacka on 7/25/2024.
//

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Space.h"
#include "Player.h"

class Gameplay {
public:
    void turn();
    static void getSpaceMenu(Player* player, Space* space);

};



#endif //GAMEPLAY_H
