//
// Created by zacka on 7/12/2024.
//

#ifndef UTILITY_H
#define UTILITY_H
#include "OwnableSpaces.h"


class Utility : public OwnableSpaces {
    bool monopoloy = false;
public:
    Utility(short spaceIndex, string spaceName) : OwnableSpaces(150, spaceIndex, std::move(spaceName)) {}
    short getRent();
    void displayInfo();
};



#endif //UTILITY_H
