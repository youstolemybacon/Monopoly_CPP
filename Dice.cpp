//
// Created by zacka on 7/13/2024.
//

#include "Dice.h"
#include <ctime>

bool Dice::rollDice()
{
    srand(time(0));
    bool doubles = false;
    short dice1 = rand() % 6 + 1;
    short dice2 = rand() % 6 + 1;
    roll = dice1 + dice2;

    // Check for doubles
    if(dice1 == dice2)
    {
        doubles = true;
    }
    else
    {
        doubles = false;
    }
    return doubles;
}

short Dice::getRoll()
{
    return roll;
}
