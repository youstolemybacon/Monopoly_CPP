//
// Created by zacka on 7/15/2024.
//

#include "Jail.h"

Jail::Jail() : Space(10, "Jail") {}

void Jail::bail(Player* prisoner)
{
    if(prisoner->pay(50))
    {
        release(prisoner);
    }
}

void Jail::release(Player* prisoner)
{
    prisoner->setJailSentence(0);
}
