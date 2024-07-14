//
// Created by zacka on 7/13/2024.
//

#ifndef DICE_H
#define DICE_H

#include <random>

class Dice {
private:
    short roll;
public:
    bool rollDice();
    short getRoll();
};



#endif //DICE_H
