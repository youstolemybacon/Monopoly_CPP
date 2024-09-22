//
// Created by zacka on 7/4/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include "Property.h"
#include "Railroad.h"
#include <vector>

#include "Player.h"
#include "Utility.h"

class Board {
private:
public:
    Board();
    ~Board();
    static vector<Space*> board;
    static Space* getSpace(short spaceIndex);
    static vector<Property*> getOwnedProperties(const Player* player);
    static vector<Railroad*> getOwnedRailroads(const Player* player);
    static vector<Utility*> getOwnedUtilities(const Player* player);
    static vector<OwnableSpaces*> getOwnedSpaces(const Player* player);
};



#endif //BOARD_H
