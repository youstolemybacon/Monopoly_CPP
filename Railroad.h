//
// Created by zacka on 7/4/2024.
//

#ifndef RAILROAD_H
#define RAILROAD_H

#include "Space.h"

class Railroad : Space {
private:
    short rent = 25;
    short price = 200;
    short spaceIndex;
    string spaceName;

public:
    Railroad(short spaceIndex, string spaceName);
    void displayInfo() override;
};


#endif //RAILROAD_H
