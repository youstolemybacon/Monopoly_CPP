//
// Created by Victoria Hendren on 6/15/24.
//

#ifndef CHANCE_H
#define CHANCE_H

#include <vector>
#include "Deck.h"
#include "Space.h"

using namespace std;

class Chance : public Space {
private:
public:
    Chance(short spaceIndex);
    static Deck chanceDeck;
    void spaceMenu(Player* player) override;

};



#endif //CHANCE_H
