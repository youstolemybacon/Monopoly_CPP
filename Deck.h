//
// Created by Zack on 4/28/2024.
//

#include <iostream>
#include <random>
#include <chrono>
#include <vector>

#ifndef MONOPOLY_SIM_COMMUNITYCHEST_H
#define MONOPOLY_SIM_COMMUNITYCHEST_H

using namespace std;

class Deck {
private:
    enum Cards {};
    vector<Cards> drawPile;
    vector<Cards> discardPile;
public:
    void shuffle();
    Cards draw();
};


#endif //MONOPOLY_SIM_COMMUNITYCHEST_H
