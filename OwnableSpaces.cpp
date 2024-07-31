//
// Created by zacka on 7/12/2024.
//

#include "OwnableSpaces.h"
#include <limits>

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

void OwnableSpaces::spaceMenu(Player* player)
{
    cout << "This is a placeholder!";
}
