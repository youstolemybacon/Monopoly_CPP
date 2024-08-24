//
// Created by zacka on 7/12/2024.
//

#include <limits>
#include "Players.h"
#include "OwnableSpaces.h"

#include "Board.h"

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
        << " at a price of $" << highestBid << "." << endl;
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

    cout << "You landed on " << getSpaceName() << ". " << endl;
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
        cout << "You are the owner of this space. Enjoy your free parking!" << endl;
    }
    else
    {
        cerr << "Could not determine owner." << endl;
    }
}

void OwnableSpaces::unownedMenu(Player* currentPlayer)
{
    enum UnownedMenuOptions
{
    DEFAULT = 0,
    BUY,
    AUCTION,
    MORTGAGE,
    INFO,
    OWNED,
    END_TURN
};
    short userInput = 0;
    UnownedMenuOptions menuSelection = DEFAULT;

    while(menuSelection != END_TURN) {
        cout << this->getSpaceName() << " is unowned. The following actions are available: \n"
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
        case BUY:
            if (this->buy(currentPlayer))
            {
                menuSelection = END_TURN;
            }
            break;
        case AUCTION:
            this->auction(Players::playerList);
            menuSelection = END_TURN;
            break;
        case MORTGAGE:
            cout << "Mortgages are not implemented." << endl;
            break;
        case INFO:
            this->displayInfo();
            break;
        case OWNED:
            printSpaces(Board::getOwnedSpaces(currentPlayer));
            break;
        default:
            cerr << "Invalid input!" << endl;
        }
    }
}

void OwnableSpaces::ownedMenu(Player* currentPlayer, Player* owner)
{
    enum OwnedMenuOptions
    {
        DEFAULT = 0,
        PAY,
        MORTGAGE,
        END_TURN
    };

    short userInput = 0;
    OwnedMenuOptions menuSelection = DEFAULT;

    while(menuSelection != END_TURN)
    {
        cout << "This property is owned by " << owner->name << ". The cost of rent is ";
        short rent = getRent();
        cout << "$" << rent << ".\n "
                "The following actions are available: \n"
                "   [1] Pay\n"
                "   [2] Mortgage\n";
        cin >> userInput;
        cin.clear();
        menuSelection = static_cast<OwnedMenuOptions>(userInput);

        switch(menuSelection)
        {
        case PAY:
            currentPlayer->pay(rent, owner);
            menuSelection = END_TURN;
            break;
        case MORTGAGE:
            cout << "Mortgages are not implemented." << endl;
            break;
        default:
            cerr << "Invalid input!" << endl;
        }
    }
}

void OwnableSpaces::printSpaces(const vector<OwnableSpaces*>& spaces)
{
    short userInput;
    bool exitMenu = false;

    if (spaces.empty())
    {
        cout << "You own nothing... that is pretty sad. I wish you luck in the remaining game you need it!" << endl;
        return;
    }

    while (!exitMenu)
    {
        short spaceNumber = 1;

        // Print the owned spaces
        cout << endl << "The spaces are printed below. Select the property to view more space info: \n"
                        "[0] Back" << endl;
        for (const auto space : spaces)
        {
            cout << "[" << spaceNumber << "]" << " " << space->getSpaceName() << endl;
            spaceNumber++;
        }
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
            if (userInput > spaces.size())
            {
                cout << "The value entered is outside of the range." << endl;
            }
            // Display the space info
            else
            {
                spaces[userInput - 1]->displayInfo();
            }
        }
    }
}
