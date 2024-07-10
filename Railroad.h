//
// Created by zacka on 7/4/2024.
//

#ifndef RAILROAD_H
#define RAILROAD_H

#include "Space.h"

class Railroad : public Space {
private:
    short rent = 25;
    short price = 200;
public:
    Railroad(short spaceIndex, string spaceName);
    Railroad() = default;
    void displayInfo() override;
};


#endif //RAILROAD_H