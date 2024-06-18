//
// Created by Zack on 4/20/2024.
//

#include "Player.h"

#include <utility>

Player::Player(string name) {
    this->name = name;
}

int Player::getSpace() const {
    return space;
}

void Player::setSpace(int space) {
    this->space = space;
}

void Player::roll() {
    dice[0] = rand() % 6 + 1;
    dice[1] = rand() % 6 + 1;
}

const int *Player::getDice() const {
    return dice;
}

void Player::setDice(int dice_1, int dice_2) {
    dice[0] = dice_1;
    dice[1] = dice_2;
}

bool Player::compareDice() {
    return dice[0] == dice[1];
}

void Player::move() {
    space += dice[0] + dice[1];
    space %= 40;
    spaceHistory[space]++;

    if(dice[0] != dice[1])
    {
        moves++;
    }
}

const int *Player::getSpaceHistory() const {
    return spaceHistory;
}

void Player::setMoney(int money) {
    this->money = money;
}

int const Player::getMoney() {
    return money;
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
