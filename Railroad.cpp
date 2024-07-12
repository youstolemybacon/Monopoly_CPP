//
// Created by zacka on 7/4/2024.
//

#include "Railroad.h"

#include <utility>

Railroad::Railroad(short spaceIndex, string spaceName) : OwnableSpaces(200, spaceIndex, std::move(spaceName)) {}

short Railroad::getRent()
{

    return 0;
}

void Railroad::displayInfo()
{

}
