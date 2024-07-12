//
// Created by zacka on 7/4/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include "Property.h"
#include "Railroad.h"
#include <vector>

class Board {
private:
public:
    Board();
    ~Board();
    vector<Space*> board;
    void print(short spaceIndex);
    Space* getSpace(short spaceIndex) const;
    void getOwnedProperties(const Player* player);
};



#endif //BOARD_H
