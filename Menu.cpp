//
// Created by zacka on 8/22/2024.
//

#include "Menu.h"
#include <iostream>

#include "Board.h"
#include "OwnableSpaces.h"
#include "Players.h"


using namespace std;

void Menu::ownableSpaceMenu(Player* currentPlayer, OwnableSpaces* ownableSpace)
{
    Player* owner = ownableSpace->getOwner();

    cout << "You landed on " << ownableSpace->getSpaceName() << ". " << endl;
    if(owner == nullptr)
    {
        unownedMenu(currentPlayer, ownableSpace);
    }
    else if(owner != currentPlayer)
    {
        ownedMenu(currentPlayer, owner, ownableSpace);
    }
    else if(owner == currentPlayer)
    {
        cout << "You are the owner of this space. Enjoy your free parking!" << endl;
    }
    else
    {
        cerr << "Could not determine owner." << endl;
    }
}

void Menu::unownedMenu(Player* currentPlayer, OwnableSpaces* ownableSpace)
{
    short userInput = 0;
    UnownedMenuOptions menuSelection = UnownedMenuOptions::DEFAULT;

    while(menuSelection != UnownedMenuOptions::END_TURN) {
        cout << ownableSpace->getSpaceName() << " is unowned. The following actions are available: \n"
        "   [1] Buy\n"
        "   [2] Auction\n"
        "   [3] Mortgage\n"
        "   [4] Info\n"
        "   [5] Owned\n";
        cin >> userInput;
        cin.clear();
        menuSelection = static_cast<UnownedMenuOptions>(userInput);

        switch (menuSelection)
        {
        case UnownedMenuOptions::BUY:
            if (ownableSpace->buy(currentPlayer))
            {
                menuSelection = UnownedMenuOptions::END_TURN;
            }
            break;
        case UnownedMenuOptions::AUCTION:
            ownableSpace->auction(Players::playerList);
            menuSelection = UnownedMenuOptions::END_TURN;
            break;
        case UnownedMenuOptions::MORTGAGE:
            cout << "Mortgages are not implemented." << endl;
            break;
        case UnownedMenuOptions::INFO:
            ownableSpace->displayInfo();
            break;
        case UnownedMenuOptions::OWNED:
            auto ownedSpaces = Board::getOwnedSpaces(currentPlayer);
            Player::printSpaces(ownedSpaces);
            break;
        default:
            cerr << "Invalid input!" << endl;
        }
    }
}

void Menu::ownedMenu(Player* currentPlayer, Player* owner, OwnableSpaces* ownableSpace)
{
    short userInput = 0;
    OwnedMenuOptions menuSelection = OwnedMenuOptions::DEFAULT;

    while(menuSelection != OwnedMenuOptions::END_TURN)
    {
        cout << "This property is owned by " << owner->name << ". The cost of rent is ";
        const short rent = ownableSpace->getRent();
        cout << "$" << rent << ".\n "
                "The following actions are available: \n"
                "   [1] Pay\n"
                "   [2] Mortgage\n";
        cin >> userInput;
        cin.clear();
        menuSelection = static_cast<OwnedMenuOptions>(userInput);

        switch(menuSelection)
        {
        case OwnedMenuOptions::PAY:
            currentPlayer->pay(rent, owner);
            menuSelection = OwnedMenuOptions::END_TURN;
            break;
        case OwnedMenuOptions::MORTGAGE:
            cout << "Mortgages are not implemented." << endl;
            break;
        default:
            cerr << "Invalid input!" << endl;
        }
    }
}