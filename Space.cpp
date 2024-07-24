//
// Created by Victoria Hendren on 6/16/24.
//

#include "Space.h"
#include <iostream>
#include <utility>

#include "Chance.h"
#include "CommunityChest.h"
#include "Go.h"
#include "GoToJail.h"
#include "IncomeTax.h"
#include "Jail.h"
#include "LuxuryTax.h"
#include "Property.h"
#include "Railroad.h"
#include "Utility.h"

using namespace std;

Space::Space(short spaceIndex, string spaceName) : spaceIndex(spaceIndex), spaceName(spaceName)
{
    this->spaceIndex = spaceIndex;
    this->spaceName = std::move(spaceName);
}

void Space::spaceMenu(Player* player)
{
    cout << "This is a placeholder!";
}

string Space::getSpaceName()
{
    return spaceName;
}

short Space::getSpaceIndex()
{
    return spaceIndex;
}

Space::SpaceTypes Space::getType(Space* space)
{
    if (dynamic_cast<Property*>(space) != nullptr)
    {
        return PROPERTY;
    }

    if (dynamic_cast<Railroad*>(space) != nullptr)
    {
        return RAILROAD;
    }

    if (dynamic_cast<Utility*>(space) != nullptr)
    {
        return UTILITY;
    }

    if (dynamic_cast<Chance*>(space) != nullptr)
    {
        return CHANCE;
    }

    if (dynamic_cast<CommunityChest*>(space) != nullptr)
    {
        return COMMUNITY_CHEST;
    }

    if (dynamic_cast<Go*>(space) != nullptr)
    {
        return GO;
    }

    if (dynamic_cast<GoToJail*>(space) != nullptr)
    {
        return GO_TO_JAIL;
    }

    if (dynamic_cast<Jail*>(space) != nullptr)
    {
        return JAIL;
    }

    if (dynamic_cast<IncomeTax*>(space) != nullptr)
    {
        return INCOME_TAX;
    }

    if (dynamic_cast<LuxuryTax*>(space) != nullptr)
    {
        return LUXURY_TAX;
    }
}
