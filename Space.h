//
// Created by Victoria Hendren on 6/16/24.
//

#ifndef SPACE_H
#define SPACE_H

#include <iostream>

using namespace std;

class Space {
private:
    Space(int spaceIndex, string spaceName);
    int spaceIndex;
    string const spaceName;
public:
    void const landed();
};



#endif //SPACE_H
