//
// Created by Zack on 5/2/2024.
//

#ifndef MONOPOLY_SIM_PROPERTY_H
#define MONOPOLY_SIM_PROPERTY_H

#include <iostream>

#include "OwnableSpaces.h"
#include "Space.h"

using namespace std;

class Property : public OwnableSpaces {
private:
    short rent[6];
    short houses = 0;
    short housePrice;
public:
    Property(short rent_1,short rent_2,short rent_3,short rent_4,short rent_5,short rent_6,short housePrice,short spaceIndex,string spaceName,short price);
    void build(short buildHouses);
    short getHousePrice();
    short getRent() override;
    void displayInfo() override;
};


#endif // MONOPOLY_SIM_PROPERTY_H