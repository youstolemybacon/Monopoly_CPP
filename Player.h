//
// Created by Zack on 4/20/2024.
//

#ifndef MONOPOLY_SIM_PLAYER_H
#define MONOPOLY_SIM_PLAYER_H

#include <iostream>
#include "Board.h"
#include "Property.h"
#include "Railroad.h"
#include "Utility.h"

class Board;
class Property;
class Railroad;
class Utility;


using namespace std;

class Player {
public:
    Player(string name);
    Player() = default;

    int getSpace() const;
    void setSpace(int space);
    short getJailSentence();
    void setJailSentence(short jailSentence);

    void roll();
    void move();

    const int getDice() const;
    void setDice(int dice_1, int dice_2);
    bool compareDice();

    const int *getSpaceHistory() const;
    void displaySpaceHistory() const;

    void printMoney() const;
    void printProperties();

    bool pay(short cost, Player& beneficiary);
    bool pay(short cost);

    bool buy(Property* property);
    bool buy(Railroad* railroad);
    bool buy(Utility* utility);

    int money = 1500;
    string name;
    static Board board;
private:
    short jailSentence{};
    int space = 0;
    int dice[2] = {0};
    int spaceHistory[40] = {0};
    double moves = 0;
};
#endif //MONOPOLY_SIM_PLAYER_H
