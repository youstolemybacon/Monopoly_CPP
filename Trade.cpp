//
// Created by zacka on 10/8/2024.
//

#include "Trade.h"
#include <iostream>

#include "Players.h"
#include "Board.h"

using namespace std;

Trade::Trade(Player* tradeInitiator) : tradeInitiator(tradeInitiator)
{
    tradeData[tradeInitiator] = TradeData{};
}

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
    tradeData[tradeReceiver] = TradeData{};

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
            ownedPropertiesSelection();
            break;
        case MONEY:
            moneySelection();
            break;
        case PREVIEW:
            previewTrade();
            break;
        default:
            cout << "Invalid input... please try again \n";
        }
    }
}

Player* Trade::playerSelection()
{
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
        return tradeInitiator;
        break;
    case 2:
        return tradeReceiver;
        break;
    default:
        cout << "Invalid input... please try again \n";
        playerSelection();
        break;
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
        //initiatorOwnedOffer = this->ownedPropertiesSelection(tradeInitiator);
        break;
    case 2:
        //receiverOwnedOffer = this->ownedPropertiesSelection(tradeReceiver);
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
    cout << "   Money: " << endl << ""
            "      $" << tradeData[tradeInitiator].money << endl << ""
            "   Properties: " << endl;
    for (auto property : tradeData[tradeInitiator].assetOffer)
    {
        cout << "      [" << index << "] " << property->getSpaceName() << endl;
        index++;
    }
    cout << endl;

    index = 1;
    cout << tradeReceiver->name << " -> " << tradeInitiator->name << ": " << endl;
    cout << "   Money: " << endl << ""
            "      $" << tradeData[tradeReceiver].money << endl << ""
            "   Properties: " << endl;
    for (auto property : tradeData[tradeReceiver].assetOffer)
    {
        cout << "      [" << index << "] " << property->getSpaceName() << endl;
        index++;
    }
    cout << endl;
}

void Trade::ownedPropertiesSelection()
{
    short userInput;
    bool exitMenu = false;

    Player* player = playerSelection();

    auto ownedSpaces = Board::getOwnedSpaces(player);
     if (ownedSpaces.empty())
     {
         cout << "You own nothing... that is pretty sad. I wish you luck in the remaining game you need it!" << endl;
         return;
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

        // If user input is 0 no action is taken. If it is not zero use the input to reference the corresponding space info
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
                for (auto space : tradeData[player].assetOffer)
                {
                    // If in assetOffer already remove it from the list
                    if (newSpace == space)
                    {
                        tradeData[player].assetOffer.erase(tradeData[player].assetOffer.begin() + index);
                        match = true;
                        break;
                    }
                    index++;
                }
                if (!match)
                {
                    tradeData[player].assetOffer.push_back(newSpace);
                }
            }
        }
    }
}

void Trade::moneySelection(Player* player)
{
    // Check if player is null
    if (!player)
    {
        player = playerSelection();
    }

    // Get amount of money for offer
    int moneyOffer = 0;
    player->printMoney();
    cout << "Enter the amount of money to offer:" << endl;
    cin >> moneyOffer;
    cin.clear();

    // Ensure offer is valid
    if(moneyOffer <= player->money && moneyOffer >= 0)
    {
        tradeData[player].money = moneyOffer;
    }
    else
    {
        cout << "Invalid value, please try again." << endl;
        moneySelection(player);
    }

}
