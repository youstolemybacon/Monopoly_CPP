//
// Created by Zack on 5/2/2024.
//

#ifndef MONOPOLY_SIM_PROPERTY_H
#define MONOPOLY_SIM_PROPERTY_H

#include <iostream>
#include "Space.h"
#include "Player.h"

using namespace std;

class Property : public Space{
private:
    short rent[6];
    short houses = 0;
    short housePrice;
    short price;
    Player* owner = nullptr;
public:
    Property(short rent[6], short houseCost, short spaceIndex, string spaceName, short price);
    void build(short buildHouses);
    int chargeRent(Player& player);
    short getRent();
    short getPrice();
    short getHousePrice();
    void displayPropertyInfo();
    bool isOwned();
    void changeOwner(Player* newOwner);
};


#endif //MONOPOLY_SIM_PROPERTY_H
