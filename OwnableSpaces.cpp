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
                if (playerList.size() == 1)
                {
                    break;
                }
                i %= playerList.size(); // Reset index to 0 if at the max value in the lsit
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

void OwnableSpaces::mortgageSpace()
{
    // Check that the property is not mortgaged
    if (!mortgaged)
    {
        const short mortgageAmount = getPrice() / 2;
        // Pay the player the mortgage amount
        owner->income(mortgageAmount);
        mortgaged = true;
    }
    else
    {
        cout << "This property is already mortgaged.";
    }
}

void OwnableSpaces::unmortgageSpace()
{
    if (mortgaged == true)
    {
        // If player can pay mortgage value plus 10%
        if (owner->pay(getPrice() / 2 + getPrice() * 0.1))
        {
            mortgaged = false;
        }
    }
    else
    {
        cout << "This property is not mortgaged.";
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

bool OwnableSpaces::getMortgage() const
{
    return mortgaged;
}

void OwnableSpaces::setMortgage(bool mortgaged)
{
    this->mortgaged = mortgaged;
}


bool OwnableSpaces::buy(Player* buyer, short price)
{
    if(buyer->pay(price))
    {
        this->changeOwner(buyer);
        cout << "Congratulations, " << buyer->name << " you are the proud owner of " << this->getSpaceName() << "!" << endl;
        return true;
    }
    return false;
}

bool OwnableSpaces::buy(Player* buyer)
{
    if(buyer->pay(this->getPrice()))
    {
        this->changeOwner(buyer);
        cout << "Congratulations, " << buyer->name << " you are the proud owner of " << this->getSpaceName() << "!" << endl;
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
        "   [3] Info\n"
        "   [4] Owned\n";
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
        case INFO:
            this->displayInfo();
            break;
        case OWNED:
            spaceInfoMenu(Board::getOwnedSpaces(currentPlayer));
            break;
        default:
            menuSelection = DEFAULT;
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
        OWNED,
        BANKRUPTCY,
        END_TURN
    };

    short userInput = 0;
    OwnedMenuOptions menuSelection = DEFAULT;
    short rent = getRent(currentPlayer);

    while(menuSelection != END_TURN)
    {
        cout << "This property is owned by " << owner->name << ". The cost of rent is $" << rent << "." << endl << endl
                << "The following actions are available:" << endl
                << "   [1] Pay\n"
                << "   [2] Owned" << endl
                << "   [3] Declare Bankruptcy" << endl;

        cin >> userInput;
        cin.clear();
        menuSelection = static_cast<OwnedMenuOptions>(userInput);

        switch(menuSelection)
        {
            case PAY:
                if (currentPlayer->pay(rent, owner))
                {
                    menuSelection = END_TURN;
                }
                break;
            case OWNED:
                spaceInfoMenu(Board::getOwnedSpaces(currentPlayer));
                break;
            case BANKRUPTCY:
                if (currentPlayer->bankruptcy(owner))
                {
                    menuSelection = END_TURN;
                }
                break;
        default:
            menuSelection = DEFAULT;
            cerr << "Invalid input!" << endl;
        }
    }
}

void OwnableSpaces::spaceInfoMenu(const vector<OwnableSpaces*>& spaces)
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
        cout << "The spaces are printed below. Select the property to view more space info: \n"
                        "   [0] Back" << endl;

        printSpaces(spaces, 1);

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
                spaces[userInput - 1]->spaceSelectedFromMenu();
            }
        }
    }
}

void OwnableSpaces::printSpaces(const vector<OwnableSpaces*>& spaces, short menuNumber)
{
    for (const auto space : spaces)
    {
        cout << "   [" << menuNumber << "]" << " ";
        space->displaySpace();
        cout << endl;
        menuNumber++;
    }
}

void OwnableSpaces::displaySpace()
{
    cout << this->getSpaceName();
}

void OwnableSpaces::spaceSelectedFromMenu()
{
    short menuSelection;
    bool exitMenu = false;
    enum menuOptions
    {
        BACK,
        INFO,
        MORTGAGE
    };

    while (!exitMenu)
    {
        // Print menu options
        cout << "The following actions are available:\n"
                "   [0] Back\n"
                "   [1] Info\n"
                "   [2] Mortgage\n";

        // Get user input
        cin >> menuSelection;
        cin.clear();

        switch (static_cast<menuOptions>(menuSelection))
        {
        case BACK:
            exitMenu = true;
            break;
        case INFO:
            displayInfo();
            break;
        case MORTGAGE:
            if (mortgaged)
            {
                unmortgageSpace();
            }
            else
            {
                mortgageSpace();
            }
            break;
        default:
            cout << "Invalid input\n";
        }
    }
}
