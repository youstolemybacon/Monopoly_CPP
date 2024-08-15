//
// Created by zacka on 7/4/2024.
//

#include "Railroad.h"
#include <cmath>
#include "Board.h"
#include "Player.h"

Railroad::Railroad(short spaceIndex, string spaceName) : OwnableSpaces(200, spaceIndex, std::move(spaceName)) {}

short Railroad::getRent()
{
    return std::pow( 2, getOwner()->getRailroadsOwned()) * 25 / 2;
}

void Railroad::displayInfo()
{

}

void Railroad::spaceMenu(Player* currentPlayer)
{
    Player* propertyOwner = getOwner();

    cout << endl << "You landed on " << getSpaceName() << ". ";
    if(propertyOwner == nullptr)
    {
        unownedMenu(currentPlayer);
    }
    else if(propertyOwner != currentPlayer)
    {
        ownedMenu(currentPlayer, propertyOwner);
    }
    else if(propertyOwner == currentPlayer)
    {
        cout << "Enjoy your free parking!" << endl;
    }
    else
    {
        cerr << "Could not determine owner of property.";
    }
}

bool Railroad::buy(Player* buyer, short price)
{
    const bool paid = OwnableSpaces::buy(buyer, price);

    if (paid)
    {
       buyer->incrementRailroadsOwned();
    }

    return paid;
}

bool Railroad::buy(Player* buyer)
{
    const bool paid = OwnableSpaces::buy(buyer);

    if (paid)
    {
        buyer->incrementRailroadsOwned();
    }

    return paid;
}
