//
// Created by zacka on 7/15/2024.
//

#ifndef JAIL_H
#define JAIL_H
#include <vector>

#include "Player.h"


class Jail : public Space {
public:
    Jail();
    void bail(Player* prisoner);
    void release(Player* prisoner);
};



#endif //JAIL_H
