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
    if(houses == 1)
    {
        cout << "There is now " << houses << " house on " << this->getSpaceName() << endl;
    }
    else if(houses == 5)
    {
        cout << "There is now 1 hotel on " << this->getSpaceName() << endl;
    }
    else
    {
        cout << "There are now " << houses << " houses on " << this->getSpaceName() << endl;
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
    cout << "  RENT $" << rent[0] << endl;
    cout << "  With 1 House... $" << rent[1] << endl;
    cout << "  With 2 House... $" << rent[2] << endl;
    cout << "  With 3 House... $" << rent[3] << endl;
    cout << "  With 4 House... $" << rent[4] << endl;
    cout << "  With HOTEL $" << rent[5] << endl;
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


