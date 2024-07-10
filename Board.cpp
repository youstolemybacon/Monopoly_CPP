//
// Created by zacka on 7/4/2024.
//

#include "Board.h"

void Board::print(short spaceIndex)
{
    cout << spaces[spaceIndex]->getSpaceName();
}
