//
// Created by Zack on 5/2/2024.
//

#include <iostream>

#ifndef MONOPOLY_SIM_PROPERTY_H
#define MONOPOLY_SIM_PROPERTY_H

using namespace std;

class Property {
private:
    string name;
    short rent[6];
    short houses = 0;
    short houseCost;
    bool isOwned = false;
    bool isUtility;
    bool isRailroad;
public:
    Property(string propertyName, short rent[6], short houseCost);
    void build(short buildHouses);
    int chargeRent();
    int chargeRent(int diceRoll);
};


#endif //MONOPOLY_SIM_PROPERTY_H
