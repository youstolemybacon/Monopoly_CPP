//
// Created by zacka on 7/15/2024.
//

#ifndef GOTOJAIL_H
#define GOTOJAIL_H
#include "Space.h"


class GoToJail : public Space {
public:
    GoToJail();
    void arrest(Player* suspect);
    void spaceMenu(Player* player);
};



#endif //GOTOJAIL_H
