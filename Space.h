//
// Created by Victoria Hendren on 6/16/24.
//

#ifndef SPACE_H
#define SPACE_H

#include <iostream>

using namespace std;


class Space {
private:
    short spaceIndex;
    string spaceName;

public:
    virtual ~Space() = default;
    virtual void displayInfo() = 0;


    Space(int spaceIndex, string spaceName);
    string getSpaceName();

    short getSpaceIndex();
};



#endif //SPACE_H
