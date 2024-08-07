//
// Created by zacka on 7/12/2024.
//

#include <limits>
#include "Players.h"
#include "OwnableSpaces.h"

OwnableSpaces::OwnableSpaces(short price, short spaceIndex, string spaceName)
    : Space(spaceIndex, std::move(spaceName))
{
    this->price = price;
}

void OwnableSpaces::auction(vector<Player*> playerList)
{
    cout << "Welcome to the auction for " << this->getSpaceName() << ". Each player will be prompted for their bid." << endl;
    cout << "To drop out of the bid simply enter in 0. " << endl;

    short highestBid = 0;
    short currentBid = 0;
    Player* highestBidder = nullptr;


    while(playerList.size() != 1)
    {
        for(int i = 0; i < playerList.size();)
        {
            Player* player = playerList[i];

            cout << player->name << ", the highest bid is " << highestBid << ". You currently have $" << player->money << endl << "Enter your bid: " << endl;
            cin >> currentBid;

            if(cin.fail())
            {
                cin.clear();
                cout << "Invalid input, please try again." << endl;
            }
            else if(currentBid > player->money)
            {
                cout << "You do not have enough money to play this bet." << endl;
            }
            else if(currentBid > highestBid)
            {
                highestBid = currentBid;
                highestBidder = player;
                i++; // Increment for loop index
            }
            else if(currentBid == 0)
            {
                playerList.erase(playerList.begin() + i);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                i++; // Increment for loop index
            }
            else
            {
                cout << "Invalid input, the bid is too low. Please try again." << endl;
            }
        }
    }

    if(highestBidder != nullptr)
    {
        cout << "Congratulations " << highestBidder->name << " you won the auction for " << this->getSpaceName()
        << "at a price of $" << highestBid << "." << endl;
        this->buy(highestBidder, highestBid);
    }
    else
    {
        cout << "No one put a bid on " << this->getSpaceName() << ". It remains in the banks possession." << endl;
    }
}

short OwnableSpaces::getPrice()
{
    return price;
}

bool OwnableSpaces::isOwned()
{
    return this->owner != nullptr;
}

void OwnableSpaces::changeOwner(Player* newOwner)
{
    this->owner = newOwner;
}

Player* OwnableSpaces::getOwner() const
{
    return this->owner;
}

bool OwnableSpaces::buy(Player* buyer, short price)
{
    if(buyer->pay(price))
    {
        this->changeOwner(buyer);
        cout << "Congratulations, you are the proud ownder of " << this->getSpaceName() << "!" << endl;
        return true;
    }
    return false;
}

bool OwnableSpaces::buy(Player* buyer)
{
    if(buyer->pay(this->getPrice()))
    {
        this->changeOwner(buyer);
        cout << "Congratulations, you are the proud ownder of " << this->getSpaceName() << "!" << endl;
        return true;
    }
    return false;
}

void OwnableSpaces::spaceMenu(Player* currentPlayer)
{
    Player* owner = getOwner();

    cout << "You landed on " << getSpaceName() << ". ";
    if(owner == nullptr)
    {
        unownedMenu(currentPlayer);
    }
    else if(owner != currentPlayer)
    {
        ownedMenu(currentPlayer, owner);
    }
    else if(owner == currentPlayer)
    {
        cout << "Enjoy your free parking!" << endl;
    }
    else
    {
        cerr << "Could not determine owner.";
    }
}

void OwnableSpaces::unownedMenu(Player* currentPlayer)
{
    short menuSelection = 0;

    while(static_cast<UnownedMenuOptions>(menuSelection) != UnownedMenuOptions::END_TURN) {
        cout << this->getSpaceName() << " is unowned. The following actions are available: \n"
        "   [1] Buy\n"
        "   [2] Auction\n"
        "   [3] Mortgage\n";
        cin >> menuSelection;
        cin.clear();

        auto menuSelectionEnum = static_cast<UnownedMenuOptions>(menuSelection);
        if(menuSelectionEnum == UnownedMenuOptions::BUY)
        {
            this->buy(currentPlayer);
            menuSelection = 4; // End turn
            cout << "Ending turn" << endl;
        }
        else if(menuSelectionEnum == UnownedMenuOptions::AUCTION)
        {
            this->auction(Players::playerList);
            menuSelection = 4; // End turn
            cout << "Ending turn" << endl;
        }
        else if (menuSelectionEnum == UnownedMenuOptions::MORTGAGE)
        {
            cout << "Mortgages are not implemented." << endl;
        }
        else
        {
            cerr << "Invalid input!" << endl;
        }
    }
}

void OwnableSpaces::ownedMenu(Player* currentPlayer, Player* owner)
{
    short menuSelection = 0;

    while(static_cast<OwnedMenuOptions>(menuSelection) != OwnedMenuOptions::END_TURN)
    {
        cout << "This property is owned by " << owner->name << ". The cost of rent is " << getRent() << ".\n "
                    "The following actions are available: \n"
                    "   [1] Pay\n"
                    "   [2] Mortgage\n";
        cin >> menuSelection;

        switch(static_cast<OwnedMenuOptions>(menuSelection))
        {
        case OwnedMenuOptions::PAY:
            currentPlayer->pay(this->getRent(), owner);
            break;
        case OwnedMenuOptions::MORTGAGE:
            cout << "Mortgages are not implemented." << endl;
            break;
        default:
            cerr << "Invalid input!" << endl;
        }
    }
}
