//
// Created by Victoria Hendren on 6/16/24.
//

#ifndef SPACE_H
#define SPACE_H

#include <iostream>

using namespace std;

class Player;

class Space {
private:
    short spaceIndex{};
    string spaceName;
public:
    Space(short spaceIndex, string spaceName);
    Space() = default;
    virtual ~Space() = default;
    virtual void spaceMenu(Player* player);
    string getSpaceName();
    short getSpaceIndex();
};

#endif //SPACE_H
