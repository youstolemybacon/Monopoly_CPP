//
// Created by zacka on 7/25/2024.
//

#include "Gameplay.h"
#include "Jail.h"
#include "Property.h"
#include "Board.h"

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
    enum PreRollMenuOptions
    {
        ROLL = 1,
        OWNED,
        TRADE
    };
    short menuSelection = 0;

    cout << player->name << ", it is your turn. The following actions are available: " << endl;

    while(static_cast<PreRollMenuOptions>(menuSelection) != ROLL)
    {
        cout <<
            "   [1] Roll\n"
            "   [2] Owned\n"
            "   [3] Trade\n";
        cin >> menuSelection;

        switch (static_cast<PreRollMenuOptions>(menuSelection))
        {
        case ROLL:
            player->move();
            break;
        case OWNED:
            OwnableSpaces::spaceInfoMenu(Board::getOwnedSpaces(player));
            break;
        case TRADE:
            cout << "Trading is not implemented" << endl;
            break;
            default:
                cerr << "Invalid input!" << endl;
        }
    }
}
