//
// Created by zacka on 7/15/2024.
//

#include "GoToJail.h"

#include "Player.h"

GoToJail::GoToJail() : Space(30, "Go To Jail") {};

void GoToJail::spaceMenu(Player* player)
{
    player->setJailSentence(3);
    player->setSpace(10);
    cout << "GO TO JAIL! \n";
}
