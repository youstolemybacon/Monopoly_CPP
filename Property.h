//
// Created by zacka on 7/22/2024.
//

#ifndef MONOPOLY_SIM_PropertyNew_H
#define MONOPOLY_SIM_PropertyNew_H

#include <iostream>
#include "OwnableSpaces.h"

class OwnableSpaces;

class Property : public OwnableSpaces {
public:
    enum class PropertyGroup
    {
        BROWN,
        LIGHT_BLUE,
        PINK,
        ORANGE,
        RED,
        YELLOW,
        GREEN,
        BLUE
    };
    PropertyGroup propertyGroup;
private:
    enum class OwnedMenuOptions
    {
        DEFAULT = 0,
        PAY,
        MORTGAGE,
        END_TURN
    };
    enum class UnownedMenuOptions
    {
        DEFAULT = 0,
        BUY,
        AUCTION,
        MORTGAGE,
        END_TURN
    };
    short rent[6];
    short houses = 0;
    short housePrice;
public:
    Property(short rent_1,short rent_2,short rent_3,short rent_4,short rent_5,short rent_6,short housePrice,short spaceIndex,string spaceName,short price, PropertyGroup propertyGroup);
    void build(short buildHouses);
    short getHousePrice();
    short getRent() override;
    void displayInfo() override;
};


#endif // MONOPOLY_SIM_PropertyNew_H
