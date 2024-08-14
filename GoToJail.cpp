//
// Created by zacka on 7/15/2024.
//

#include "GoToJail.h"

#include "Player.h"

GoToJail::GoToJail() : Space(30, "Go To Jail") {};

void GoToJail::arrest(Player* suspect)
{
    suspect->setJailSentence(3);
    suspect->setSpace(10);
    cout << "GO TO JAIL!" << endl;
}

void GoToJail::spaceMenu(Player* player)
{
    cout << "Go to Jail";
}
