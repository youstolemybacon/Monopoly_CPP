//
// Created by zacka on 7/12/2024.
//

#include "Utility.h"
#include "Dice.h"
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

short Utility::getRent(Player* player)
{
    Dice dice;
    short rent = 0;


    cin.ignore(); // clear cin buffer

    // If it is a monopoly of chance modification
    if(monopoloy || player->getChanceModifier())
    {
        cout << "determined by roll x 10." << endl;
        cout << "Hit enter to roll for rent!" << endl;
        cin.get();
        dice.rollDice();
        rent = dice.getRoll() * 10;
        player->setChanceModifier(false);
    }
    else
    {
        cout << "determined by roll x 4." << endl;
        cout << "Hit enter to roll for rent!" << endl;
        cin.get();
        dice.rollDice();
        rent = dice.getRoll() * 4;
    }

    cout << "You rolled a " << dice.getRoll() << " making rent ";

    return rent;
}

void Utility::displayInfo()
{
    cout << endl << "_______________________________________" << endl;
    cout << endl << getSpaceName() << endl;
    cout << endl << " If one \"Utility\" is owned, rent is 4 \ntimes amount shown on dice." << endl;
    cout << " If both \"Utilities\" are owned, rent is\n10 times amount shown on dice." << endl;
    cout << endl << "Mortgage Value: $" << this->getPrice() / 2 << endl;
    cout << endl << "_______________________________________" << endl;
}
