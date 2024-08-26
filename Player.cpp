//
// Created by Zack on 4/20/2024.
//

#include "Player.h"
#include "Board.h"

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

short Player::getJailSentence()
{
    return jailSentence;
}

void Player::setJailSentence(short jailSentence)
{
    this->jailSentence = jailSentence;
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
}

const int Player::getDice() const {
    return dice[0] + dice[1];
}

bool Player::compareDice() {
    return dice[0] == dice[1];
}

bool Player::move() {
    roll();
    spaceIndex += dice[0] + dice[1];

    if (spaceIndex > 39)
    {
        playerBoard.getSpace(0)->spaceMenu(this); // Calling passing go menu
    }

    spaceIndex %= 40;
    spaceHistory[spaceIndex]++;

    if(dice[0] != dice[1])
    {
        moves++;
        return false; // Doubles were not rolled
    }
    return true; // Doubles were rolled
}

const int *Player::getSpaceHistory() const {
    return spaceHistory;
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
        cout << "TRANSACTIONS: \n";
        cout << "   " << name << ": $" << money + cost << " - $" << cost << " = $" << money << "\n";
        cout << "   " << beneficiary->name << ": $" << money - cost << " + $" << cost << " = $" << money << "\n\n";

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
    printMoney();
}

void Player::printMoney() const
{
    cout << this->name << " you have $" << this->money << endl << endl;
}

void Player::displaySpaceHistory() const {
    cout << "Go: " << spaceHistory[0] / moves << "%" << endl;
    cout << "Mediterranean Avenue: " << spaceHistory[1] / moves << "%" << endl;
    cout << "Community Chest 1: " << spaceHistory[2] / moves << "%" << endl;
    cout << "Baltic Avenue: " << spaceHistory[3] / moves << "%" << endl;
    cout << "Income Tax: " << spaceHistory[4] / moves << "%" << endl;
    cout << "Reading Railroad: " << spaceHistory[5] / moves << "%" << endl;
    cout << "Oriental Avenue: " << spaceHistory[6] / moves << "%" << endl;
    cout << "Chance 1: " << spaceHistory[7] / moves << "%" << endl;
    cout << "Vermont Avenue: " << spaceHistory[8] / moves << "%" << endl;
    cout << "Connecticut: " << spaceHistory[9] / moves << "%" << endl;
    cout << "Jail: " << spaceHistory[10] / moves << "%" << endl;
    cout << "St Charles Place: " << spaceHistory[11] / moves << "%" << endl;
    cout << "Electric Company: " << spaceHistory[12] / moves << "%" << endl;
    cout << "States Avenue: " << spaceHistory[13] / moves << "%" << endl;
    cout << "Virginia Avenue: " << spaceHistory[14] / moves << "%" << endl;
    cout << "Pennsylvania Railroad: " << spaceHistory[15] / moves << "%" << endl;
    cout << "St James Place: " << spaceHistory[16] / moves << "%" << endl;
    cout << "Community Chest 2: " << spaceHistory[17] / moves << "%" << endl;
    cout << "Tennessee Avenue: " << spaceHistory[18] / moves << "%" << endl;
    cout << "New York Avenue: " << spaceHistory[19] / moves << "%" << endl;
    cout << "Free Parking: " << spaceHistory[20] / moves << "%" << endl;
    cout << "Kentucky Avenue: " << spaceHistory[21] / moves << "%" << endl;
    cout << "Chance 2: " << spaceHistory[22] / moves << "%" << endl;
    cout << "Indiana Avenue: " << spaceHistory[23] / moves << "%" << endl;
    cout << "Illinois Avenue: " << spaceHistory[24] / moves << "%" << endl;
    cout << "BO Railroad: " << spaceHistory[25] / moves << "%" << endl;25 ,
    cout << "Atlantic Avenue: " << spaceHistory[26] / moves << "%" << endl;
    cout << "Ventnor Avenue: " << spaceHistory[27] / moves << "%" << endl;
    cout << "Water Works: " << spaceHistory[28] / moves << "%" << endl;
    cout << "Marvin Gardens: " << spaceHistory[29] / moves << "%" << endl;
    cout << "Go To Jail: " << spaceHistory[30] / moves << "%" << endl;
    cout << "Pacific Avenue: " << spaceHistory[31] / moves << "%" << endl;
    cout << "North Carolina Avenue: " << spaceHistory[32] / moves << "%" << endl;
    cout << "Community Chest 3: " << spaceHistory[33] / moves << "%" << endl;
    cout << "Pennsylvania Avenue: " << spaceHistory[34] / moves << "%" << endl;
    cout << "Short Line Railroad: " << spaceHistory[35] / moves << "%" << endl;
    cout << "Chance 3: " << spaceHistory[36] / moves << "%" << endl;
    cout << "Park Place: " << spaceHistory[37] / moves << "%" << endl;
    cout << "Luxury Tax: " << spaceHistory[38] / moves << "%" << endl;
    cout << "Boardwalk: " << spaceHistory[39] / moves << "%" << endl;
}
