//
// Created by zacka on 7/13/2024.
//

#ifndef DICE_H
#define DICE_H

#include <random>

class Dice {
private:
    static short roll;
public:
    static bool rollDice();
    static short getRoll();
};



#endif //DICE_H
