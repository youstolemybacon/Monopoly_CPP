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
#include "Property.h"
#include "Railroad.h"
#include "Utility.h"
#include "FreeParking.h"


void Gameplay::turn(Player* player)
{
    preRollMenu(player);
    spaceMenu(player);
}

void Gameplay::spaceMenu(Player* player)
{
    Space* space = player->getSpace();

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
    case Space::SpaceType::FREE_PARKING:
        dynamic_cast<FreeParking*>(space)->spaceMenu(player);
        break;
    default:
        cerr << "No Space of this type exists";
    }
}

void Gameplay::preRollMenu(Player* player)
{
    short menuSelection = 0;
    cout << "\n_____________________________________________________________________\n" << endl;
    cout << player->name << ", it is your turn. The following actions are available: " << endl;
    while(static_cast<PreRollMenuOptions>(menuSelection) != PreRollMenuOptions::ROLL)
    {
        cout <<
            "   [1] Roll\n"
            "   [2] Develop Properties\n"
            "   [3] Trade\n"
            "   [4] Mortgage" << endl;
        cin >> menuSelection;

        switch (static_cast<PreRollMenuOptions>(menuSelection))
        {
        case PreRollMenuOptions::ROLL:
            player->move();
            break;
        case PreRollMenuOptions::DEVELOP_PROPERTIES:
            cout << "Developing properties requires further development." << endl;
            break;
        case PreRollMenuOptions::TRADE:
            cout << "Trading is not implemented" << endl;
            break;
        case PreRollMenuOptions::MORTGAGE:
            cout << "Mortgage is not implemented" << endl;
            break;
            default:
                cerr << "Invalid input!" << endl;
        }
    }
}
