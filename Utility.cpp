//
// Created by zacka on 7/12/2024.
//

#include "Utility.h"

#include "Player.h"

void Utility::setRent(short ownedUtilities)
{
    switch (ownedUtilities)
    {
    case 0:
        cerr << "No utilities owned";
        break;
    case 1:
        monopoloy = false;
        break;
    case 2:
        monopoloy = true;
        break;
    default:
        cerr << "Too many utilities owned";

    }
}

short Utility::getRent()
{
    short rent;
    if(monopoloy)
    {
        cout << "You landed on a utility! " << getOwner()->name << " owns both Utilities increasing the rent. Rent is determined by roll x 10." << endl;
        cout << "Hit enter to roll for rent!" << endl;
        cin.get();
        getOwner()->roll;
        rent = getOwner()->getDice() * 10;
    }
    else
    {
        cout << "You landed on a utility! Rent is determined by roll x 4." << endl;
        cout << "Hit enter to roll for rent!" << endl;
        cin.get();
        getOwner()->roll;
        rent = getOwner()->getDice() * 4;
    }
    return rent;
}
