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
    short rent[6];
    short houses = 0;
    short housePrice;
public:
    Property(short rent_1,short rent_2,short rent_3,short rent_4,short rent_5,short rent_6,short housePrice,short spaceIndex,string spaceName,short price, PropertyGroup propertyGroup);
    void build(short buildHouses);
    short getHousePrice();
    short getRent() override;
    void displayInfo() override;

    static vector<Property*> getPropertyGroup(PropertyGroup color);
    static vector<Property*> getMonopolies(const Player* player);
    static bool monopolyCheck(const Player* player, PropertyGroup color);
    static void developPropertiesMenu(Player* player);
};


#endif // MONOPOLY_SIM_PropertyNew_H
