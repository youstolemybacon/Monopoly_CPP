//
// Created by Victoria Hendren on 6/16/24.
//

#include "Space.h"
#include <iostream>

using namespace std;

Space::Space(int spaceIndex, string spaceName) {
    this->spaceIndex = spaceIndex;
    this->spaceName = spaceName;
}

string Space::getSpaceName()
{
    return spaceName;
}