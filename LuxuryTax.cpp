//
// Created by zacka on 7/15/2024.
//

#include "LuxuryTax.h"
#include "OwnableSpaces.h"
#include "Board.h"
#include "Player.h"

LuxuryTax::LuxuryTax() : Space(38, "Luxury Tax") {}

void LuxuryTax::spaceMenu(Player* player)
{
    {
        enum UnownedMenuOptions
        {
            DEFAULT = 0,
            PAY,
            OWNED,
            END_TURN
        };
        short userInput = 0;
        UnownedMenuOptions menuSelection = DEFAULT;

        // Calculate the tax
        short tax = player->money * 0.1;

        while(menuSelection != END_TURN) {
            cout << "You landed on " << this->getSpaceName() << ". \n"
                    "TAX = 75 \n\n";

            cout << "The following actions are available: \n"
                    "   [1] Pay\n"
                    "   [2] Owned\n";
            cin >> userInput;
            cin.clear();
            menuSelection = static_cast<UnownedMenuOptions>(userInput);

            switch (menuSelection)
            {
            case PAY:
                if (player->pay(75))
                {
                    menuSelection = END_TURN;
                }
                break;
            case OWNED:
                OwnableSpaces::spaceInfoMenu(Board::getOwnedSpaces(player));
                break;
            default:
                cerr << "Invalid input!" << endl;
            }
        }
    }
}