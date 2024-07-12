//
// Created by Zack on 5/2/2024.
//

#ifndef MONOPOLY_SIM_PROPERTY_H
#define MONOPOLY_SIM_PROPERTY_H

#include <iostream>
#include "Space.h"

using namespace std;

class Property : public Space {
private:
    short rent[6];
    short houses = 0;
    short housePrice;
    short price;
    Player* owner = nullptr;
public:
    Property(short rent_1,short rent_2,short rent_3,short rent_4,short rent_5,short rent_6,short housePrice,short spaceIndex,string spaceName,short price);
    Property();
    void build(short buildHouses);
    short getRent();
    short getPrice();
    short getHousePrice();
    void displayInfo();
    bool isOwned();
    void changeOwner(Player* newOwner);
    Player* getOwner() const;
};


#endif // MONOPOLY_SIM_PROPERTY_H