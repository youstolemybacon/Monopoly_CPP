//
// Created by Zack on 5/2/2024.
//

#include "Property.h"

Property::Property(short rent_1, short rent_2, short rent_3, short rent_4, short rent_5, short rent_6, short housePrice,
    short spaceIndex, string spaceName, short price) : rent{rent_1, rent_2, rent_3, rent_4, rent_5, rent_6},
    housePrice(housePrice), OwnableSpaces(price, spaceIndex, spaceName) {}

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

short Property::getRent()
{
    return rent[houses];
}

short Property::getHousePrice()
{
    return housePrice;
}

void Property::displayInfo() {
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
