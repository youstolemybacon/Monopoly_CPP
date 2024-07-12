//
// Created by zacka on 7/4/2024.
//

#include "Railroad.h"

Railroad::Railroad(short spaceIndex, string spaceName) : Space(spaceIndex, spaceName)
{

}

void Railroad::displayInfo()
{

}

Player* Railroad::getOwner()
{
    return this->owner;
}

short Railroad::getPrice()
{
    return price;
}

void Railroad::changeOwner(Player* newOwner)
{
    this->owner = newOwner;
}
