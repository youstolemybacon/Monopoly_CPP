//
// Created by zacka on 7/14/2024.
//

#ifndef GO_H
#define GO_H
#include "Space.h"


class Go : public Space{
private:
public:
    Go();
    void spaceMenu(Player* player) override;
};

#endif //GO_H
