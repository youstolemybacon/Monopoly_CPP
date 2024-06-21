//
// Created by Victoria Hendren on 6/16/24.
//

#ifndef SPACE_H
#define SPACE_H

#include <iostream>

using namespace std;

class Space {
private:
    int spaceIndex;
    string spaceName;
public:
    Space(int spaceIndex, string spaceName);
    string getSpaceName();
};



#endif //SPACE_H
