//
// Created by Zack on 4/20/2024.
//

#include "Player.h"
#include "Board.h"
#include "Jail.h"
#include "Players.h"

int Player::getSpaceIndex() const {
    return spaceIndex;
}

void Player::setSpace(int spaceIndex) {
    this->spaceIndex = spaceIndex;
}

Space* Player::getSpace()
{
    return playerBoard.getSpace(spaceIndex);
}

short Player::getJailSentence() const
{
    return jailSentence;
}

void Player::setJailSentence(short jailSentence)
{
    this->jailSentence = jailSentence;
}

bool Player::isJailed() const
{
    if (this->getJailSentence() > 0)
    {
        return true;
    }
    return false;
}


short Player::getRailroadsOwned() const
{
    return railroadsOwned;
}

void Player::incrementRailroadsOwned()
{
    railroadsOwned++;
}

void Player::decrementRailroadsOwned()
{
    railroadsOwned--;
}

void Player::roll() {

    dice[0] = rand() % 6 + 1;
    dice[1] = rand() % 6 + 1;
    cout << "ROLL:\n"
         << "   " << dice[0] << " + " << dice[1] << " = " << dice[0] + dice[1] << "\n\n";
}

const int Player::getDice() const {
    return dice[0] + dice[1];
}

bool Player::compareDice() {
    return dice[0] == dice[1];
}

void Player::move() {
    roll();

    doubles = 0;
    // Check for doubles
    if (dice[0] == dice[1])
    {
        doubles++;
        if (doubles == 3)
        {
            setJailSentence(3);
        }
    }

    // Check if in jail
    if (this->isJailed())
    {
        if (jailSentence == 1)
        {
            Jail::bail(this);
        }
        else if (doubles != 0)
        {
            cout << "You rolled doubles you escaped from Jail! \n";
            setJailSentence(0);
        }
        else
        {
            cout << "You did not roll doubles. You are still in Jail. \n";
            jailSentence--;
            return;
        }
        
    }

    spaceIndex += dice[0] + dice[1];

    // Pass go check
    if (spaceIndex > 39 && spaceIndex != 0)
    {
        Board::getSpace(0)->spaceMenu(this); // Calling passing go menu
    }

    spaceIndex %= 40;
}

bool Player::pay(const short cost, Player* beneficiary)
{
    if(this->money > cost)
    {
        // Subtract cost from players money
        this->money -= cost;
        // Add cost to players money
        beneficiary->money += cost;

        // Print transaction details
        cout << "\nPAYMENT SUCCESSFUL\n";
        cout << "   TRANSACTIONS: \n";
        cout << "      " << name << ": $" << money + cost << " - $" << cost << " = $" << money << "\n";
        cout << "      " << beneficiary->name << ": $" << beneficiary->money - cost << " + $" << cost << " = $" << beneficiary->money << "\n\n";

        // Player succuessfully paid
        return true;
    }

    // Player could not afford payment
    cout << "\nPAYMENT FAILED\n";
    cout << "   TRANSACTION: $" << money << " - $" << cost << " = -$" << cost - money << "\n\n";
    return false; // Player cannot afford
}

bool Player::pay(const short cost)
{
    if (money > cost)
    {
        // Subtract cost from players money
        this->money -= cost;

        // Print transaction details
        cout << "\nPAYMENT SUCCESSFUL\n";
        cout << "   TRANSACTION: $" << money + cost << " - $" << cost << " = $" << money << "\n\n";

        // Player succuessfully paid
        return true;
    }

    // Player could not afford payment
    cout << "\nPAYMENT FAILED\n";
    cout << "   TRANSACTION: $" << money << " - $" << cost << " = -$" << cost - money << "\n\n";
    return false;
}

void Player::income(short income)
{
    money += income;
    cout << "\nPAYMENT SUCCESSFUL\n";
    cout << "   TRANSACTION: $" << money - income << " + $" << income << " = $" << money << "\n\n";
}

void Player::setDoubles(short doubles)
{
    this->doubles = doubles;
}

short Player::getDoubles() const
{
    return doubles;
}

void Player::setChanceModifier(bool chanceModifier)
{
    this->chanceModifier = chanceModifier;
}

bool Player::getChanceModifier()
{
    return chanceModifier;
}

void Player::setGetOutOfJailFree(short count)
{
    this->getOutOfJailFree = count;
}
short Player::getGetOutOfJailFree() const
{
    return getOutOfJailFree;
}

//void Player::trade()
//{
//    short playerIndex = 1;
//    short menuSelection = -1;
//
//    // Select player to trade with
//    cout << "Select player you wish to trade with: \n ";
//    for (auto player : Players::getOtherPlayers(this))
//    {
//        if (this != player)
//        {
//            cout << "   [" << playerIndex << "] " << player->name << "\n";
//            playerIndex++;
//        }
//        cin >> menuSelection;
//        cin.clear();
//        auto tradingPlayer = Players::playerList[menuSelection];
//
//        enum MenuOptions
//        {
//            BACK,
//            OWNED,
//            MONEY,
//            OFFER
//        };
//
//        menuSelection = -1;
//        cout << "The following actions are available: \n"
//                "   [0] Back \n"
//                "   [1] Owned \n"
//                "   [2] Money \n"
//                "   [3] Offer \n";
//
//        cin >> menuSelection;
//        cin.clear();
//
//        switch (static_cast<MenuOptions>(menuSelection))
//        {
//        case BACK:
//            return;
//        case OWNED:
//            tradeOwnedMenu(tradingPlayer);
//            break;
//        case MONEY:
//            break;
//        case OFFER:
//            break;
//        default:
//            cout << "Invalid input... please try again \n";
//        }
//    }
//}
//
//std::vector<OwnableSpaces*> Player::tradeOwnedMenu(Player* tradingPlayer)
//{
//    std::vector<OwnableSpaces*> spacesToTrade = {};
//    int menuSelection = -1;
//    cout << "Select player: \n"
//            "   [0] Back \n"
//            "   [1] " << this->name << "\n"
//            "   [2] " << tradingPlayer->name << "\n";
//    cin >> menuSelection;
//    cin.clear();
//
//    switch (menuSelection)
//    {
//    case 0:
//        break;
//    case 1:
//        this->tradeOwnedPropertiesSelection();
//        break;
//    case 2:
//        tradingPlayer->tradeOwnedPropertiesSelection();
//        break;
//    default:
//        cout << "Invalid input... please try again \n";
//        break;
//    }
//}
//
//std::vector<OwnableSpaces*> Player::tradeOwnedPropertiesSelection()
//{
//    short userInput;
//    bool exitMenu = false;
//    auto ownedSpaces = Board::getOwnedSpaces(this);
//    std::vector<OwnableSpaces*> spacesToTrade = {};
//
//     if (ownedSpaces.empty())
//     {
//         cout << "You own nothing... that is pretty sad. I wish you luck in the remaining game you need it!" << endl;
//         return spacesToTrade;
//     }
//
//     while (!exitMenu)
//     {
//         cout << "The spaces are printed below. Select the space to add to trade: \n"
//                         "   [0] Back" << endl;
//
//        OwnableSpaces::printSpaces(ownedSpaces, 1);
//
//        // Get user input
//        cin >> userInput;
//        cin.clear();
//
//        // If user input is 0 no action is taken. If it is not zero use the input to reference the correspondings space info
//        if(userInput == 0)
//        {
//            exitMenu = true;
//        }
//        else
//        {
//            // Check if the user input is within the range of the vector
//            if (userInput > ownedSpaces.size())
//            {
//                cout << "The value entered is outside of the range." << endl;
//            }
//            // Add space to lists of spaces to trade
//            else
//            {
//                spacesToTrade.push_back(ownedSpaces[userInput - 1]);
//            }
//        }
//    }
//    return spacesToTrade;
//}

bool Player::operator==(const Player& other) const
{
    return this->name == other.name;
}

void Player::printMoney() const
{
    cout << this->name << " you have $" << this->money << endl << endl;
}

void Player::printPlayerInfo() const
{
    Space* currentSpace = Board::getSpace(spaceIndex);
    cout << name << ": \n"
         << "   Money: $" << money << "\n"
         << "   Space: " << currentSpace->getSpaceName() << "\n\n";
}
