//
// Created by zacka on 10/8/2024.
//

#include "Trade.h"
#include <iostream>

#include "Players.h"
#include "Board.h"

using namespace std;

Trade::Trade(Player* tradeInitiator) : tradeInitiator(tradeInitiator) {}

void Trade::trade()
{
    short playerIndex = 1;
    short menuSelection = -1;

    // Select player to trade with
    cout << "Select player you wish to trade with: \n";
    auto otherPlayers = Players::getOtherPlayers(tradeInitiator);
    for (auto player : otherPlayers)
    {
        if (tradeInitiator != player)
        {
            cout << "   [" << playerIndex << "] " << player->name << "\n";
            playerIndex++;
        }
    }
    cin >> menuSelection;
    cin.clear();
    tradeReceiver = otherPlayers[menuSelection - 1];

    enum MenuOptions
    {
        DEFAULT = -1,
        BACK = 0,
        OWNED = 1,
        MONEY = 2,
        PREVIEW = 3
    };

    while(static_cast<MenuOptions>(menuSelection) != BACK)
    {
        menuSelection = -1;
        cout << "The following actions are available: \n"
                "   [0] Back \n"
                "   [1] Owned \n"
                "   [2] Money \n"
                "   [3] Preview \n";

        cin >> menuSelection;
        cin.clear();

        switch (static_cast<MenuOptions>(menuSelection))
        {
        case BACK:
            return;
        case OWNED:
            ownedMenu();
            break;
        case MONEY:
            break;
        case PREVIEW:
            previewTrade();
            break;
        default:
            cout << "Invalid input... please try again \n";
        }
    }
}

void Trade::ownedMenu()
{
    std::vector<OwnableSpaces*> spacesToTrade = {};
    int menuSelection = -1;
    cout << "Select player: \n"
            "   [0] Back \n"
            "   [1] " << this->tradeInitiator->name << "\n"
            "   [2] " << this->tradeReceiver->name << "\n";
    cin >> menuSelection;
    cin.clear();

    switch (menuSelection)
    {
    case 0:
        break;
    case 1:
        initiatorOwnedOffer = this->ownedPropertiesSelection(tradeInitiator);
        break;
    case 2:
        receiverOwnedOffer = this->ownedPropertiesSelection(tradeReceiver);
        break;
    default:
        cout << "Invalid input... please try again \n";
        break;
    }
}

void Trade::previewTrade()
{
    short index = 1;
    cout << tradeInitiator->name << " -> " << tradeReceiver->name << ": " << endl;
    cout << "   Properties: " << endl;
    for (auto property : initiatorOwnedOffer)
    {
        cout << "      [" << index << "] " << property->getSpaceName() << endl;
        index++;
    }
    cout << endl;

    index = 1;
    cout << tradeReceiver->name << " -> " << tradeInitiator->name << ": " << endl;
    cout << "   Properties: " << endl;
    for (auto property : receiverOwnedOffer)
    {
        cout << "      [" << index << "] " << property->getSpaceName() << endl;
        index++;
    }
    cout << endl;
}

std::vector<OwnableSpaces*> Trade::ownedPropertiesSelection(Player* player)
{
    short userInput;
    bool exitMenu = false;
    auto ownedSpaces = Board::getOwnedSpaces(player);
        std::vector<OwnableSpaces*> spacesToTrade = {};

     if (ownedSpaces.empty())
     {
         cout << "You own nothing... that is pretty sad. I wish you luck in the remaining game you need it!" << endl;
         return spacesToTrade;
     }

     while (!exitMenu)
     {
         // Print out prompt for selection
         cout << "The spaces are printed below. Select the space to add to trade: \n"
                         "   [0] Back" << endl;
        OwnableSpaces::printSpaces(ownedSpaces, 1);

         // Get user input
        cin >> userInput;
        cin.clear();

        // If user input is 0 no action is taken. If it is not zero use the input to reference the correspondings space info
        if(userInput == 0)
        {
            exitMenu = true;
        }
        else
        {
            // Check if the user input is within the range of the vector
            if (userInput > ownedSpaces.size())
            {
                cout << "The value entered is outside of the range." << endl;
            }
            // Add space to lists of spaces to trade
            else
            {
                int index = 0;
                bool match = false;
                auto newSpace = ownedSpaces[userInput - 1];
                for (auto space : spacesToTrade)
                {
                    if (newSpace == space)
                    {
                        spacesToTrade.erase(spacesToTrade.begin() + index);
                        match = true;
                        break;
                    }
                    index++;
                }
                if (!match)
                {
                    spacesToTrade.push_back(ownedSpaces[userInput - 1]);
                }
            }
        }
    }
    return spacesToTrade;
}
