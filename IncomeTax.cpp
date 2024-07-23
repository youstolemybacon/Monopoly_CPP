//
// Created by zacka on 7/15/2024.
//

#include "IncomeTax.h"

#include "Player.h"

IncomeTax::IncomeTax() : Space(4, "Luxury Tax") {}

bool IncomeTax::payTaxes(Player* taxPayer)
{
    if(taxPayer->pay(200))
    {
        return true;
    }
    return false;
}

void IncomeTax::spaceMenu(Player* player)
{
    cout << "Placeholder";
}
