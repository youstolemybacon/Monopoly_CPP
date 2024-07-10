//
// Created by zacka on 7/4/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include "Property.h"
#include "Railroad.h"
#include <vector>
#include <memory>


class Board {
private:
    vector<Space*> board;

public:
    Board();
    void print(short spaceIndex);
    Space* getSpace(short spaceIndex) const;
    void getOwnedProperties(const shared_ptr<Player>& player);
};



#endif //BOARD_H
