//
// Created by zacka on 7/15/2024.
//

#ifndef JAIL_H
#define JAIL_H

#include "Player.h"
#include "Space.h"


class Jail : public Space {
public:
    Jail();
    static bool bail(Player* prisoner);
    static void release(Player* prisoner);
    void spaceMenu(Player* player);
    static bool bailMenuOption(Player* player);
};



#endif //JAIL_H
