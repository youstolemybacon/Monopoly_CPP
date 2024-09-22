//
// Created by zacka on 7/15/2024.
//

#ifndef GOTOJAIL_H
#define GOTOJAIL_H
#include "Space.h"


class GoToJail : public Space {
public:
    GoToJail();
    void spaceMenu(Player* player) override;
};

#endif //GOTOJAIL_H
