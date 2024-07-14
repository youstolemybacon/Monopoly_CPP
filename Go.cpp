//
// Created by zacka on 7/14/2024.
//

#include "Go.h"

#include "Player.h"


Go::Go() : Space(0, "Go") {}

void Go::spaceMenu(Player* player)
{
    cout << "COLLECT $200 SALARY AS YOU PASS GO" << endl;
    player->pay(200);
    player->printMoney();
};
