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

short Property::getRent()
{
    return rent[houses];
}

short Property::getPrice()
{
    return price;
}

short Property::getHousePrice()
{
    return housePrice;
}

void Property::displayPropertyInfo() {
    cout << endl << getSpaceName() << endl;
    cout << endl;
    cout << "  RENT $" << getRent(0) << endl;
    cout << "  With 1 House... $" << getRent(1) << endl;
    cout << "  With 2 House... $" << getRent(2) << endl;
    cout << "  With 3 House... $" << getRent(3) << endl;
    cout << "  With 4 House... $" << getRent(4) << endl;
    cout << "  With HOTEL $" << getRent(5) << endl;
    cout << endl;
    cout << "  Mortgage Value $" << getPrice() / 2 << endl;
    cout << "  Houses cost $" << getHousePrice() << " each" << endl;
    cout << "  Hotels, $" << getHousePrice() << " plus 4 houses" << endl;
}

Property::Property(short rent[6], short housePrice, short spaceIndex, string spaceName, short price) : Space(spaceIndex, spaceName){
    for(int i = 0; i < 6; i++){
        this->rent[i] = rent[i];
    }
    this->housePrice = housePrice;
    this->price = price;
}


