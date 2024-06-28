//
// Created by Zack on 4/20/2024.
//

#ifndef MONOPOLY_SIM_PLAYER_H
#define MONOPOLY_SIM_PLAYER_H

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Property.h"
#include "Space.h"


using namespace std;

class Player {
public:
    Player(string name);
    Player() = default;

    string getName() const;
    void setName(string name);

    int getSpace() const;
    void setSpace(int space);

    void roll();
    void move();

    const int getDice() const;
    void setDice(int dice_1, int dice_2);
    bool compareDice();

    const int *getSpaceHistory() const;
    void displaySpaceHistory() const;


    bool payPlayer(const short cost, Player& beneficiary);
    bool payBank(const short cost);
    bool buy(Property& propertyForSell);

    int money = 1500;
    string name;
private:
    int space = 0;
    int dice[2] = {0};
    int spaceHistory[40] = {0};
    double moves = 0;
    vector<Space> propertiesOwned;
};


#endif //MONOPOLY_SIM_PLAYER_H
