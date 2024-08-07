//
// Created by zacka on 7/22/2024.
//

#ifndef MONOPOLY_SIM_PropertyNew_H
#define MONOPOLY_SIM_PropertyNew_H

#include <iostream>
#include "OwnableSpaces.h"

class OwnableSpaces;

class Property : public OwnableSpaces {
private:
    short rent[6];
    short houses = 0;
    short housePrice;
    enum class OwnedMenuOptions
    {
        PAY = 1,
        MORTGAGE,
        END_TURN
    };
    enum class UnownedMenuOptions
    {
        BUY = 1,
        AUCTION,
        MORTGAGE,
        END_TURN
    };
public:
    Property(short rent_1,short rent_2,short rent_3,short rent_4,short rent_5,short rent_6,short housePrice,short spaceIndex,string spaceName,short price);
    void build(short buildHouses);
    short getHousePrice();
    short getRent() override;
    void displayInfo() override;
    void spaceMenu(Player* currentPlayer);
    void unownedMenu(Player* currentPlayer);
    void ownedMenu(Player* currentPlayer, Player* propertyOwner);
};


#endif // MONOPOLY_SIM_PropertyNew_H
