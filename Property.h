//
// Created by Zack on 5/2/2024.
//

#include <iostream>
#include "Space.h"

#ifndef MONOPOLY_SIM_PROPERTY_H
#define MONOPOLY_SIM_PROPERTY_H

using namespace std;

class Property : public Space{
private:
    short rent[6];
    short houses = 0;
    short housePrice;
    short price;
    bool isOwned = false;
public:
    Property(short rent[6], short houseCost, short spaceIndex, string spaceName, short price);
    void build(short buildHouses);
    int chargeRent();
    int chargeRent(int diceRoll);
    short getRent();
    short getPrice();
    short getHousePrice();
    void displayPropertyInfo();
};


#endif //MONOPOLY_SIM_PROPERTY_H
