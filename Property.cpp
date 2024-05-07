//
// Created by Zack on 5/2/2024.
//

#include "Property.h"

void Property::build(short buildHouses) {
    if(houses + buildHouses > 5) {
        cout << "You are attempting to exceed the house limit cheater!" << endl;
    }
    else if(isRailroad || isUtility) {
        cout << "You know better... you cannot build a house here." << endl;
    }
    else {
        houses += buildHouses;
    }
}

int Property::chargeRent() {
    if(!isUtility) {
        return rent[houses];
    }
    else {
        cerr << "Charge Rent Error!";
    }
    return 0;
}

int Property::chargeRent(int diceRoll) {
    if(isUtility) {
        return rent[houses] * diceRoll;
    }
    else {
        cerr << "Charge Rent Error";
    }
}

Property::Property(string propertyName, short *rent, short houseCost) {
    name = std::move(propertyName);

    for(int i; i < 6; i++){
        this->rent[i] = rent[i];
    }

    this->houseCost = houseCost;
}


