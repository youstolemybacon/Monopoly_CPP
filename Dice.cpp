//
// Created by zacka on 7/13/2024.
//

#include "Dice.h"
#include "iostream"
#include <ctime>

using namespace std;

bool Dice::rollDice()
{
    bool doubles = false;
    short dice1 = rand() % 6 + 1;
    short dice2 = rand() % 6 + 1;
    roll = dice1 + dice2;

    cout << "ROLL:\n"
         << "   " << dice1 << " + " << dice2 << " = " << dice1 + dice2 << "\n\n";

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
