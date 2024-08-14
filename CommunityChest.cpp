//
// Created by zacka on 7/15/2024.
//

#include "CommunityChest.h"

CommunityChest::CommunityChest(const short spaceIndex) : Space(spaceIndex, "Community Chest") {}

void CommunityChest::spaceMenu(Player* player)
{
    cout << "Community Chest" << endl;
};
