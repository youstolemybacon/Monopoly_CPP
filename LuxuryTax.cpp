//
// Created by zacka on 7/15/2024.
//

#include "LuxuryTax.h"

#include "Player.h"

LuxuryTax::LuxuryTax() : Space(38, "Luxury Tax") {}

bool LuxuryTax::payTaxes(Player* taxPayer)
{
    if(taxPayer->pay(75))
    {
        return true;
    }
    return false;
}
