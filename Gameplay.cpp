//
// Created by zacka on 7/25/2024.
//

#include "Gameplay.h"
#include "Jail.h"
#include "Property.h"


void Gameplay::turn(Player* player)
{
    preRollMenu(player);
    spaceMenu(player);
    cout << endl << "TURN ENDED" << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl;
}

void Gameplay::spaceMenu(Player* player)
{
    Space* space = player->getSpace();
    space->spaceMenu(player);
}

void Gameplay::preRollMenu(Player* player)
{
    short menuSelection = 0;

    cout << player->name << ", it is your turn. The following actions are available: " << endl;

    while(static_cast<PreRollMenuOptions>(menuSelection) != PreRollMenuOptions::ROLL)
    {
        cout <<
            "   [1] Roll\n"
            "   [2] Develop Properties\n"
            "   [3] Trade\n"
            "   [4] Mortgage" << endl;
        cin >> menuSelection;

        switch (static_cast<PreRollMenuOptions>(menuSelection))
        {
        case PreRollMenuOptions::ROLL:
            player->move();
            break;
        case PreRollMenuOptions::DEVELOP_PROPERTIES:
            Property::developPropertiesMenu(player);
            break;
        case PreRollMenuOptions::TRADE:
            cout << "Trading is not implemented" << endl;
            break;
        case PreRollMenuOptions::MORTGAGE:
            cout << "Mortgage is not implemented" << endl;
            break;
            default:
                cerr << "Invalid input!" << endl;
        }
    }
}
