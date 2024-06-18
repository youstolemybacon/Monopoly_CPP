//
// Created by Zack on 5/2/2024.
//

#include "Property.h"

void Property::build(short buildHouses) {
    if(houses + buildHouses > 5) {
        cout << "You are attempting to exceed the house limit cheater!" << endl;
    }
    else {
        houses += buildHouses;
    }
}

int Property::chargeRent() {
    return rent[houses];
}

Property::Property(short rent[6], short houseCost, short spaceIndex, string spaceName) : Space(spaceIndex, spaceName){
    for(int i = 0; i < 6; i++){
        this->rent[i] = rent[i];
    }
    this->houseCost = houseCost;
}


