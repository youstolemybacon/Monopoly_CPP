//
// Created by zacka on 7/12/2024.
//

#include "OwnableSpaces.h"

#include <utility>

OwnableSpaces::OwnableSpaces(short price, short spaceIndex, string spaceName)
    : Space(spaceIndex, std::move(spaceName))
{
    this->price = price;
}

short OwnableSpaces::getPrice()
{
    return price;
}

bool OwnableSpaces::isOwned()
{
    return this->owner != nullptr;
}

void OwnableSpaces::changeOwner(Player* newOwner)
{
    this->owner = newOwner;
}

Player* OwnableSpaces::getOwner() const
{
    return this->owner;
}