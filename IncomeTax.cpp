//
// Created by zacka on 7/15/2024.
//

#include "IncomeTax.h"
#include "Board.h"
#include "Player.h"
#include "OwnableSpaces.h"

IncomeTax::IncomeTax() : Space(4, "Luxury Tax") {}

bool IncomeTax::payTaxes(Player* taxPayer)
{
    if(taxPayer->pay(200))
    {
        return true;
    }
    return false;
}

void IncomeTax::spaceMenu(Player* player)
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
            cout << "You landed on " << this->getSpaceName() << ". The cost of income tax is 10% of you total money with a maximum of $200.\n"
                    "TAX: \n"
                    "   $" << player->money << " x 0.1 = $" << tax << "\n";
            if (tax > 200)
            {

                cout << "   $" << tax << " > $200 \n";
                tax = 200;
            }
            cout << "   TAX = $" << tax << "\n\n";

            cout << "The following actions are available: \n"
                    "   [1] Pay\n"
                    "   [2] Owned\n";
            cin >> userInput;
            cin.clear();
            menuSelection = static_cast<UnownedMenuOptions>(userInput);

            switch (menuSelection)
            {
            case PAY:
                if (player->pay(tax))
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
