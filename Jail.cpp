//
// Created by zacka on 7/15/2024.
//

#include "Jail.h"
#include "Board.h"

Jail::Jail() : Space(10, "Jail") {}

bool Jail::bail(Player* prisoner)
{
    if(prisoner->pay(50))
    {
        release(prisoner);
        return true;
    }
    return false;
}

void Jail::release(Player* prisoner)
{
    prisoner->setJailSentence(0);
}

void Jail::spaceMenu(Player* player)
{
    if (player->isJailed())
    {
        cout << "Jail \n";
    }
    else
    {
        cout << "Just Visiting Jail \n";
    }
}

bool Jail::bailMenuOption(Player* player)
{
    string paymentOption;
    if (player->isJailed())
    {
        int bailSelection = -1;
        while (true)
        {
            // Player has a get out of jail free card
            if (player->getGetOutOfJailFree() > 0)
            {
                paymentOption = "Get out of jail free card";
            }
            // Player does not have a get out of jail free card
            else
            {
                paymentOption = "$50";
            }
            cout << "You are currently in Jail. Would you like to pay bail ( " << paymentOption << ") to escape early: \n";
            cout << "   [0] Back \n"
                    "   [1] Yes \n"
                    "   [2] No \n";
            cin >> bailSelection;

            switch (bailSelection)
            {
            case 0:
                return false;
                break;
            case 1:
                bail(player);
                return true;
                break;
            case 2:
                return true;
                break;
            default:
                cout << "Invalid Input! \n";
            }
        }
    }
    else
    {
        return true;
    }
}
