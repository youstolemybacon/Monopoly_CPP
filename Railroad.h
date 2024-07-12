//
// Created by zacka on 7/4/2024.
//

#ifndef RAILROAD_H
#define RAILROAD_H

#include "OwnableSpaces.h"
#include "Space.h"

class Railroad : public OwnableSpaces {
private:
    short rent{};
public:
    Railroad(short spaceIndex, string spaceName);
    short getRent() override;
    void setRent(short railroadsOwned);
    void displayInfo() override;

};


#endif //RAILROAD_H
