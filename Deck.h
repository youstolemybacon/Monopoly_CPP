//
// Created by Zack on 4/28/2024.
//

#ifndef MONOPOLY_SIM_DECK_H
#define MONOPOLY_SIM_DECK_H

#include <iostream>
#include <vector>

using namespace std;

class Deck {
private:
    vector<int> discardPile {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<int> drawPile;
public:
    void shuffle();
    int draw();
};


#endif //MONOPOLY_SIM_COMMUNITYCHEST_H
