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
    enum SpaceType
    {
        SPACE,
        PROPERTY,
        RAILROAD,
        UTILITY,
        CHANCE,
        COMMUNITY_CHEST,
        GO,
        GO_TO_JAIL,
        JAIL,
        INCOME_TAX,
        LUXURY_TAX,
        FREE_PARKING,
        OTHER
    };

    Space(short spaceIndex, string spaceName);
    virtual void spaceMenu(Player* player);
    string getSpaceName();
    short getSpaceIndex();
    static SpaceType getType(Space* space);
};

#endif //SPACE_H
