//
// Created by zacka on 7/4/2024.
//

#ifndef RAILROAD_H
#define RAILROAD_H

#include "OwnableSpaces.h"

class OwnableSpaces;

class Railroad : public OwnableSpaces {
private:
    short rent{};
public:
    Railroad(short spaceIndex, string spaceName);
    short getRent() override;
    void setRent(short railroadsOwned);
    void displayInfo() override;
    void spaceMenu(Player* player) override;
    void buy(Player* buyer, short price) override;
};


#endif //RAILROAD_H
