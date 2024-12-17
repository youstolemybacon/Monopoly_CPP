//
// Created by zacka on 7/25/2024.
//

#include "Gameplay.h"
#include "Jail.h"
#include "Property.h"
#include "Board.h"
#include "Trade.h"

void Gameplay::turn(Player* player)
{
    if (!player->bankrupt)
    do
    {
        preRollMenu(player);
        spaceMenu(player);
        cout << endl << "TURN ENDED" << endl;
        cout << "-----------------------------------------------------------------------------" << endl << endl;
    } while (player->getDoubles());
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

    while(static_cast<PreRollMenuOptions>(menuSelection) != ROLL)
    {
        player->printPlayerInfo();
        cout <<
            "The following actions are available: \n"
            "   [1] Roll\n"
            "   [2] Owned\n"
            "   [3] Trade\n";
        cin >> menuSelection;

        Trade trade(player);

        switch (static_cast<PreRollMenuOptions>(menuSelection))
        {
        case ROLL:
            // If player wants to go back
            if (!Jail::bailMenuOption(player))
            {
                menuSelection = 0;
                break;
            }
            player->move();
            break;
        case OWNED:
            OwnableSpaces::spaceInfoMenu(Board::getOwnedSpaces(player));
            break;
        case TRADE:
            trade.trade();
            break;
        default:
                cerr << "Invalid input!" << endl;
        }
    }
}
