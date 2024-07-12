//
// Created by Victoria Hendren on 6/16/24.
//

#include "Space.h"
#include <iostream>
#include <utility>

using namespace std;

Space::Space(short spaceIndex, string spaceName) : spaceIndex(spaceIndex), spaceName(spaceName)
{
    this->spaceIndex = spaceIndex;
    this->spaceName = std::move(spaceName);
}

string Space::getSpaceName()
{
    return spaceName;
}

short Space::getSpaceIndex()
{
    return spaceIndex;
}
