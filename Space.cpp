//
// Created by Victoria Hendren on 6/16/24.
//

#include "Space.h"
#include <iostream>

using namespace std;

Space::Space(int spaceIndex, string spaceName) {
    this->spaceIndex = spaceIndex;
    this->spaceName = spaceName;
    cout << "Space Index: " << this->spaceIndex << endl;
    cout << "Space Name: " << this->spaceName << endl;
}

void const Space::landed() {
    cout << "You landed on " << spaceName << endl;
}
