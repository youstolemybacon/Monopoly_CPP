//
// Created by zacka on 7/4/2024.
//

#include "Railroad.h"

#include "Player.h"

Railroad::Railroad(short spaceIndex, string spaceName) : OwnableSpaces(200, spaceIndex, std::move(spaceName)) {}

short Railroad::getRent()
{
    return rent;
}

void Railroad::setRent(short railroadsOwned)
{
    switch (railroadsOwned)
    {
    case 1:
        this->rent = 25;
        break;
    case 2:
        this->rent = 50;
        break;
    case 3:
        this->rent = 100;
        break;
    case 4:
        this->rent = 200;
        break;
    default:
        cerr << "Failed to set railroad rent";
    }
}

void Railroad::displayInfo()
{

}
