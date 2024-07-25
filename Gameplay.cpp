//
// Created by zacka on 7/25/2024.
//

#include "Gameplay.h"

#include "Chance.h"
#include "CommunityChest.h"
#include "Go.h"
#include "GoToJail.h"
#include "IncomeTax.h"
#include "Jail.h"
#include "LuxuryTax.h"


void Gameplay::getSpaceMenu(Player* player, Space* space)
{
    switch(Space::getType(space))
    {
    case Space::SpaceType::PROPERTY:
        dynamic_cast<Property*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::RAILROAD:
        dynamic_cast<Railroad*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::UTILITY:
        dynamic_cast<Utility*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::CHANCE:
        dynamic_cast<Chance*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::COMMUNITY_CHEST:
        dynamic_cast<CommunityChest*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::GO:
        dynamic_cast<Go*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::GO_TO_JAIL:
        dynamic_cast<GoToJail*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::JAIL:
        dynamic_cast<Jail*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::INCOME_TAX:
        dynamic_cast<IncomeTax*>(space)->spaceMenu(player);
        break;

    case Space::SpaceType::LUXURY_TAX:
        dynamic_cast<LuxuryTax*>(space)->spaceMenu(player);
        break;

    default:
        cerr << "No Space of this type exists";
    }
}
